#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHA_NUM 26

struct TrieNode
{
    char character;
    struct TrieNode *childNodes[ALPHA_NUM];
    int isLeaf;
};

struct TrieNode *createTrieNode(char character)
{
    struct TrieNode *newNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));

    for (int i = 0; i < ALPHA_NUM; i++)
    {
        newNode->childNodes[i] = NULL;
    }
    newNode->isLeaf = 0;
    newNode->character = character;
    return newNode;
}

void freeTrie(struct TrieNode *n)
{
    for (int i = 0; i < ALPHA_NUM; i++)
    {
        if (n->childNodes[i] != NULL)
        {
            freeTrie(n->childNodes[i]);
        }
        else
        {
            continue;
        }
    }
    free(n);
}

struct TrieNode *insert(struct TrieNode *root, char *word)
{
    struct TrieNode *current = root;

    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = (int)word[i] - 'a';

        if (current->childNodes[index] == NULL)
        {
            current->childNodes[index] = createTrieNode(word[i]);
        }
        else
        {
            // The node already exists, do nothing
        }
        current = current->childNodes[index];
    }
    current->isLeaf = 1;
    return root;
}

int search(struct TrieNode *root, char *word)
{
    struct TrieNode *current = root;

    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a';

        if (current->childNodes[index] == NULL)
        {
            return 0;
        }
        current = current->childNodes[index];
    }

    if (current != NULL && current->isLeaf == 1)
    {
        return 1;
    }
    return 0;
}

int findDivergentIndex(struct TrieNode *root, char *word)
{
    struct TrieNode *current = root;
    int len = strlen(word);
    int lastIndex = 0;

    if (len == 0)
    {
        return 0;
    }

    for (int i = 0; i < len; i++)
    {
        int index = word[i] - 'a';

        if (current->childNodes[index])
        {
            for (int j = 0; j < ALPHA_NUM; j++)
            {
                if (j != index && current->childNodes[j])
                {
                    lastIndex = i + 1;
                    break;
                }
            }
            current = current->childNodes[index];
        }
    }
    return lastIndex;
}

char findLongestPrefix(struct TrieNode *root, char *word)
{
    int len = strlen(word);

    if (!word || word[0] == '\0')
    {
        return -1;
    }

    char *longestPrefix = (char *)malloc((len + 1) * sizeof(char));

    for (int i = 0; word[i] != '\0'; i++)
    {
        longestPrefix[i] = word[i];
    }
    longestPrefix[len] = '\0';

    int branchIndex = findDivergentIndex(root, longestPrefix) - 1;

    if (branchIndex >= 0)
    {
        longestPrefix[branchIndex] = '\0';
        longestPrefix = (char *)realloc(longestPrefix, (branchIndex + 1) * sizeof(char));
    }
    return *longestPrefix;
}

int isLeafNode(struct TrieNode *root, char *word)
{
    struct TrieNode *current = root;

    for (int i = 0; word[i]; i++)
    {
        int index = (int)word[i] - 'a';

        if (current->childNodes[index])
        {
            current = current->childNodes[index];
        }
    }
    return current->isLeaf;
}

struct TrieNode *deleteTrie(struct TrieNode *root, char *word)
{
    if (!root)
    {
        return 0;
    }
    if (!word || word[0] == '\0')
    {
        return root;
    }
    if (!isLeafNode(root, word))
    {
        return root;
    }

    struct TrieNode *temp = root;
    char *longestPrefix = findLongestPrefix(root, word);

    if (longestPrefix[0] == '\0')
    {
        free(longestPrefix);
        return root;
    }

    int i;

    for (i = 0; longestPrefix[i] != '\0'; i++)
    {
        int index = (int)longestPrefix[i] - 'a';

        if (temp->childNodes[index] != NULL)
        {
            temp = temp->childNodes[index];
        }
        else
        {
            free(longestPrefix);
            return root;
        }
    }

    int len = strlen(word);

    for (; i < len; i++)
    {
        int index = (int)word[i] - 'a';

        if (temp->childNodes[index])
        {
            struct TrieNode *removeNode = temp->childNodes[index];

            temp->childNodes[index] = NULL;
            freeTrie(removeNode);
        }
    }
    free(longestPrefix);
    return root;
}

void displayTrie(struct TrieNode *root)
{
    if (!root)
    {
        return;
    }

    struct TrieNode *temp = root;

    printf("%c", temp->character);

    for (int i = 0; i < ALPHA_NUM; i++)
    {
        displayTrie(temp->childNodes[i]);
    }
}

void displaySearch(struct TrieNode *root, char *word)
{
    printf("\n\nSearching for %s: ", word);
    if (search(root, word) == 0)
        printf("Not Found\n");
    else
        printf("Found!\n");
}

int main()
{
    struct TrieNode *root = createTrieNode('\0');

    root = insert(root, "hello");
    root = insert(root, "hi");
    root = insert(root, "help");

    displaySearch(root, "hi");
    displayTrie(root);

    root = deleteTrie(root, "help");
    displayTrie(root);

    freeTrie(root);

    return 0;
}