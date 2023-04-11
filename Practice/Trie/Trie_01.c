#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALHPABET_SIZE 26

struct TrieNode
{
    struct TrieNode *children[ALHPABET_SIZE];
    bool endOfWord;
};

struct Trie
{
    struct TrieNode *root;
};

struct TrieNode *createTrieNode()
{
    struct TrieNode *newNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    newNode->endOfWord = false;

    for (int i = 0; i < ALHPABET_SIZE; i++)
        newNode->children[i] = NULL;
    return newNode;
}

struct Trie *createTrie()
{
    struct Trie *trie = (struct Trie *)malloc(sizeof(struct Trie));
    trie->root = createTrieNode();
    return trie;
}

void insert(struct Trie *trie, const char *word)
{
    struct TrieNode *current = trie->root;

    for (int i = 0; i < strlen(word); i++)
    {
        int index = word[i] - 'a';

        if (current->children[index] == NULL)
            current->children[index] = createTrieNode();
        current = current->children[index];
    }
    current->endOfWord = true;
}

void insertRecursionUtil(struct TrieNode *current, const char *word, int index)
{
    if (index == strlen(word))
    {
        current->endOfWord = true;
        return;
    }

    int i = word[index] - 'a';

    if (current->children[i] == NULL)
        current->children[i] = createTrieNode();
    insertRecursionUtil(current->children[i], word, index + 1);
}

void insertRecursion(struct Trie *trie, const char *word)
{
    insertRecursionUtil(trie->root, word, 0);
}

bool search(struct Trie *trie, const char *word)
{
    struct TrieNode *current = trie->root;

    for (int i = 0; i < strlen(word); i++)
    {
        int index = word[i] - 'a';

        if (current->children[index] == NULL)
            return false;
        current = current->children[index];
    }
    return current->endOfWord;
}

bool searchRecursionUtil(struct TrieNode *current, const char *word, int index)
{
    if (index == strlen(word))
        return current->endOfWord;

    int i = word[index] - 'a';

    if (current->children[i] == NULL)
        return false;
    return searchRecursionUtil(current->children[i], word, index + 1);
}

bool searchRecursion(struct Trie *trie, const char *word)
{
    return searchRecursionUtil(trie->root, word, 0);
}

bool deleteUtil(struct TrieNode *current, const char *word, int index)
{
    if (index == strlen(word))
    {
        if (!current->endOfWord)
            return false;
        current->endOfWord = false;

        for (int i = 0; i < ALHPABET_SIZE; i++)
        {
            if (current->children[i] != NULL)
                return false;
        }

        return true;
    }

    int i = word[index] - 'a';

    if (current->children[i] == NULL)
        return false;

    bool shouldDeleteCurrentNode = deleteUtil(current->children[i], word, index + 1);

    if (shouldDeleteCurrentNode)
    {
        free(current->children[i]);
        current->children[i] = NULL;
    }

    if (!current->endOfWord)
    {
        bool hasChildren = false;

        for (int i = 0; i < ALHPABET_SIZE; i++)
        {
            if (current->children[i] != NULL)
            {
                hasChildren = true;
                break;
            }
        }

        if (!hasChildren)
            return true;
    }
    return false;
}

bool delete(struct Trie *trie, const char *word)
{
    return deleteUtil(trie->root, word, 0);
}

void freeTrieUtil(struct TrieNode *current)
{
    if (current == NULL)
        return;

    for (int i = 0; i < ALHPABET_SIZE; i++)
        freeTrieUtil(current->children[i]);

    free(current);
}

void freeTrie(struct Trie *trie)
{
    freeTrieUtil(trie->root);
    free(trie);
}

int main()
{
    struct Trie *trie = createTrie();

    insert(trie, "hello");
    insert(trie, "world");
    insert(trie, "help");
    insert(trie, "where");

    printf("Search 'hello': %s\n", search(trie, "hello") ? "Found" : "Not Found");
    printf("Search 'world': %s\n", search(trie, "world") ? "Found" : "Not Found");
    printf("Search 'hi': %s\n", search(trie, "help") ? "Found" : "Not Found");
    printf("Search 'hey': %s\n", search(trie, "hey") ? "Found" : "Not Found");

    delete (trie, "hello");

    printf("Search 'hello' after delete: %s\n", search(trie, "hello") ? "Found" : "Not Found");

    freeTrie(trie);

    return 0;
}