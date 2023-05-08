#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// This code is like a dictionary. It stores words. but only accepts words that are all lower case letters

#define ALPHABET_LETTERS 26

struct TrieNode
{
    char key;
    struct TrieNode *childNode[ALPHABET_LETTERS];
    bool endOfWord;
};

struct TrieNode *createTrieNode(char key) // 'o'
{
    struct TrieNode *newNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    for (int i = 0; i < ALPHABET_LETTERS; i++)
    {
        newNode->childNode[i] = NULL;
    }

    newNode->endOfWord = false;
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
    // help

    struct TrieNode *temp = root;

    for (int i = 0; word[i] != '\0'; i++)
    {
        // i = 4

        int index = word[i] - 'a'; // 15

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
    temp->endOfWord = true;
    return root;
}

int searchTrie(struct TrieNode *root, char *word) // hello
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
    if (temp != NULL && temp->endOfWord == true)
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

    int len = strlen(word); // 4

    char *longestPrefix = (char *)malloc((len + 1) * sizeof(char)); // 5

    for (int i = 0; word[i] != '\0'; i++)
    {
        longestPrefix[i] = word[i];
        // help [5] = help [4]
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
    return temp->endOfWord;
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
    if (!root) // root == NULL
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
    printf("\n");

    return 0;
}


// root = \0 -> childNode[7] = node1
// node1 = 'h' -> childNode[4] = node2
// node2 = 'e' -> childNode[11] = node3
// node3 = 'l' -> childNode[11] = node4
// node4 = 'l' -> childNode[14] = node5
//             -> childNode[15] = node4.1
// temp = node5 = 'o'
// node4.1 = 'p'


//         \0
//      'h' false
//      'e' false 
//      'l' false
//  'l' false 'p' true
//  'o' true
// h e l l o p