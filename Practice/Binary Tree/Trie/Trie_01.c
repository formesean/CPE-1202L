#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This code is like a dictionary. It stores words. but only accepts words that are all lower case letters

#define ALPHABET_LETTERS 26

struct TrieNode
{
    char key;
    struct TrieNode *childNode[ALPHABET_LETTERS];
    int isLeaf;
};

struct TrieNode *createTrieNode(char key)
{
    struct TrieNode *newNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    for (int i = 0; i < ALPHABET_LETTERS; i++)
    {
        newNode->childNode[i] = NULL;
    }

    newNode->isLeaf = 0;
    newNode->key = key;
    return newNode;
}

void freeTrieNode(struct TrieNode *node)
{
    for (int i = 0; i < ALPHABET_LETTERS; i++)
    {
        if (node->childNode[i] != NULL)
        {
            freeTrieNode(node->childNode[i]);
        }
        else
        {
            continue;
        }
    }
    free(node);
}

struct TrieNode *insertTrie(struct TrieNode *root, char *word)
{
    struct TrieNode *temp = root;

    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a';
        if (temp->childNode[index] == NULL)
        {
            temp->childNode[index] = createTrieNode(word[i]);
        }
        else
        {
            // Do nothing. The node already exists
        }
        temp = temp->childNode[index];
    }
    temp->isLeaf = 1;
    return root;
}

int searchTrie(struct TrieNode *root, char *word)
{
    struct TrieNode *temp = root;

    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a';
        if (temp->childNode[index] == NULL)
        {
            return 0;
        }
        temp = temp->childNode[index];
    }
    if (temp != NULL && temp->isLeaf == 1)
    {
        return 1;
    }
    return 0;
}

int checkDivergence(struct TrieNode *root, char *word)
{
    struct TrieNode *temp = root;
    int len = strlen(word);

    if (len == 0)
    {
        return 0;
    }

    int lastIndex = 0;

    for (int i = 0; i < len; i++)
    {
        int index = word[i] - 'a';

        if (temp->childNode[index] != NULL)
        {
            for (int j = 0; j < ALPHABET_LETTERS; j++)
            {
                if (j != index && temp->childNode[j] != NULL)
                {
                    lastIndex = i + 1;
                    break;
                }
            }
            temp = temp->childNode[index];
        }
    }
    return lastIndex;
}

char *findLongestPrefix(struct TrieNode *root, char *word)
{
    if (word == NULL || word[0] == '\0')
    {
        return NULL;
    }

    int len = strlen(word);

    char *longestPrefix = (char *)malloc((len + 1) * sizeof(char));

    for (int i = 0; word[i] != '\0'; i++)
    {
        longestPrefix[i] = word[i];
    }

    longestPrefix[len] = '\0';

    int branchIndex = checkDivergence(root, longestPrefix) - 1;

    if (branchIndex >= 0)
    {
        longestPrefix[branchIndex] = '\0';
        longestPrefix = (char *)realloc(longestPrefix, (branchIndex + 1) * sizeof(char));
    }

    return longestPrefix;
}

int isLeafNode(struct TrieNode *root, char *word)
{
    struct TrieNode *temp = root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = (int)word[i] - 'a';
        if (temp->childNode[index])
        {
            temp = temp->childNode[index];
        }
    }
    return temp->isLeaf;
}

struct TrieNode *deleteTrie(struct TrieNode *root, char *word)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (word == NULL || word[0] == '\0')
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
        longestPrefix = NULL;

        return root;
    }

    int i;

    for (i = 0; longestPrefix[i] != '\0'; i++)
    {
        int index = (int)longestPrefix[i] - 'a';

        if (temp->childNode[index] != NULL)
        {
            temp = temp->childNode[index];
        }
        else
        {
            free(longestPrefix);
            longestPrefix = NULL;

            return root;
        }
    }

    int len = strlen(word);

    for (; i < len; i++)
    {
        int index = (int)word[i] - 'a';
        if (temp->childNode[index] != NULL)
        {
            struct TrieNode *removeNode = temp->childNode[index];

            temp->childNode[index] = NULL;

            freeTrieNode(removeNode);
        }
    }

    free(longestPrefix);
    longestPrefix = NULL;

    return root;
}

void displayTrie(struct TrieNode *root)
{
    if (!root)
    {
        return;
    }

    struct TrieNode *temp = root;

    printf("%c ", temp->key);
    for (int i = 0; i < ALPHABET_LETTERS; i++)
    {
        displayTrie(temp->childNode[i]);
    }
}

void displaySearch(struct TrieNode *root, char *word)
{
    printf("Searching for %s: ", word);

    if (searchTrie(root, word) == 0)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("Found!\n");
    }
}

int main()
{
    struct TrieNode *root = createTrieNode('\0');

    root = insertTrie(root, "hello");
    root = insertTrie(root, "help");

    displayTrie(root);

    // printf("\n");
    // printf("\n");
    // displaySearch(root, "hello");
    // printf("\n");

    // root = deleteTrie(root, "help");
    // displayTrie(root);
    // printf("\n");
    // printf("\n");

    // displaySearch(root, "help");
    // freeTrieNode(root);
    return 0;
}