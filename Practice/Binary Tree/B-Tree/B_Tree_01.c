#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_KEYS 3

struct BTreeNode
{
    int keys[MAX_KEYS];
    struct BTreeNode *children[MAX_KEYS + 1];
    int numKeys;
    bool isLeaf;
};

// Creates a new B-Tree node
struct BTreeNode *createNode()
{
    struct BTreeNode *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    newNode->numKeys = 0;
    newNode->isLeaf = true;

    for (int i = 0; i < MAX_KEYS + 1; i++)
        newNode->children[i] = NULL;

    return newNode;
}

// Splits a child node of a B-Tree
void splitChild(struct BTreeNode *parent, struct BTreeNode *child, int index)
{
    struct BTreeNode *newNode = createNode();
    newNode->isLeaf = child->isLeaf;
    newNode->numKeys = MAX_KEYS / 2;

    for (int i = 0; i < MAX_KEYS / 2; i++)
        newNode->keys[i] = child->keys[i + MAX_KEYS / 2 + 1];

    if (!child->isLeaf)
    {
        for (int i = 0; i < MAX_KEYS / 2 + 1; i++)
            newNode->children[i] = child->children[i + MAX_KEYS / 2 + 1];
    }

    child->numKeys = MAX_KEYS / 2;

    for (int i = parent->numKeys; i > index; i--)
        parent->children[i + 1] = parent->children[i];

    parent->children[index + 1] = newNode;
    parent->children[index] = child;

    for (int i = parent->numKeys - 1; i >= index; i--)
        parent->keys[i + 1] = parent->keys[i];

    parent->keys[index] = child->keys[MAX_KEYS / 2];
    parent->numKeys++;
}

// Inserts a key into a B-Tree
void insert(struct BTreeNode **root, int key)
{
    if (*root == NULL)
    {
        *root = createNode();
        (*root)->keys[0] = key;
        (*root)->numKeys = 1;
    }
    else
    {

        if ((*root)->numKeys == MAX_KEYS)
        {
            struct BTreeNode *newNode = createNode();
            newNode->isLeaf = false;
            newNode->children[0] = *root;
            splitChild(newNode, *root, 0);

            int i = 0;

            if (newNode->keys[0] < key)
                i++;

            insert(&newNode->children[i], key);
            *root = newNode;
        }
        else
        {
            int i = (*root)->numKeys - 1;

            while (i >= 0 && (*root)->keys[i] > key)
            {
                (*root)->keys[i + 1] = (*root)->keys[i];
                i--;
            }

            (*root)->keys[i + 1] = key;
            (*root)->numKeys++;
        }
    }
}

// Searches for a key in a B-Tree
struct BTreeNode *search(struct BTreeNode *root, int key)
{
    if (root == NULL)
        return NULL;

    int i = 0;

    while (i < root->numKeys && key > root->keys[i])
        i++;

    if (root->keys[i] == key)
        return root;

    if (root->isLeaf)
        return NULL;

    return search(root->children[i], key);
}

// In order traversal display of a B-Tree
void display(struct BTreeNode *root)
{
    if (root != NULL)
    {
        int i;
        for (i = 0; i < root->numKeys; i++)
        {
            display(root->children[i]);
            printf("%d ", root->keys[i]);
        }
        display(root->children[root->numKeys]);
    }
}

int main()
{
    struct BTreeNode *root = NULL;

    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    printf("In-order traversal of the B-Tree: ");
    display(root);
    printf("\n");

    return 0;
}