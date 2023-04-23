#include <stdio.h>
#include <stdlib.h>
#define M 3

struct Node
{
    int numKeys;
    int keys[M - 1];
    struct Node *children[M];
};

struct Node *root = NULL;

#define DUPLICATE 0
#define SEARCH_FAILURE 1
#define SUCCESS 2
#define INSERT_IT 3
#define LESS_KEYS 4

void insert(int key);
int ins(struct Node *r, int x, int *y, struct Node **u);
int searchPos(int key, int *key_arr, int numKeys);
void inorder(struct Node *ptr);
void display(struct Node *root, int);

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    inorder(root);
    printf("\n\n");
    display(root, 0);

    return 0;
}

void insert(int key)
{
    struct Node *newNode;
    int upKey;
    int value = ins(root, key, &upKey, &newNode);

    if (value == DUPLICATE)
    {
        printf("Key already available\n");
    }

    if (value == INSERT_IT)
    {
        struct Node *uproot = root;
        root = (struct Node *)malloc(sizeof(struct Node));
        root->numKeys = 1;
        root->keys[0] = upKey;
        root->children[0] = uproot;
        root->children[1] = newNode;
    }
}

int ins(struct Node *ptr, int key, int *upKey, struct Node **newNode)
{
    struct Node *newPtr, *lastPtr;
    int pos, i, numKeys, splitPos, newKey, lastKey;
    int value;

    if (ptr == NULL)
    {
        *newNode = NULL;
        *upKey = key;
        return INSERT_IT;
    }
    numKeys = ptr->numKeys;
    pos = searchPos(key, ptr->keys, numKeys);

    if (pos < numKeys && key == ptr->keys[pos])
    {
        return DUPLICATE;
    }
    value = ins(ptr->children[pos], key, &newKey, &newPtr);

    if (value != INSERT_IT)
    {
        return value;
    }

    if (numKeys < M - 1)
    {
        pos = searchPos(newKey, ptr->keys, numKeys);

        for (i = numKeys; i > pos; i--)
        {
            ptr->keys[i] = ptr->keys[i - 1];
            ptr->children[i + 1] = ptr->children[i];
        }

        ptr->keys[pos] = newKey;
        ptr->children[pos + 1] = newPtr;
        ++ptr->numKeys;
        return SUCCESS;
    }

    if (pos == M - 1)
    {
        lastKey = newKey;
        lastPtr = newPtr;
    }
    else
    {
        lastKey = ptr->keys[M - 2];
        lastPtr = ptr->children[M - 1];
        for (i = M - 2; i > pos; i--)
        {
            ptr->keys[i] = ptr->keys[i - 1];
            ptr->children[i + 1] = ptr->children[i];
        }
        ptr->keys[pos] = newKey;
        ptr->children[pos + 1] = newPtr;
    }
    splitPos = (M - 1) / 2;
    (*upKey) = ptr->keys[splitPos];

    (*newNode) = (struct Node *)malloc(sizeof(struct Node));
    ptr->numKeys = splitPos;
    (*newNode)->numKeys = M - 1 - splitPos;

    for (i = 0; i < (*newNode)->numKeys; i++)
    {
        (*newNode)->children[i] = ptr->children[i + splitPos + 1];
        if (i < (*newNode)->numKeys - 1)
        {
            (*newNode)->keys[i] = ptr->keys[i + splitPos + 1];
        }
        else
        {
            (*newNode)->keys[i] = lastKey;
        }
    }
    (*newNode)->children[(*newNode)->numKeys] = lastPtr;
    return INSERT_IT;
}

int searchPos(int key, int *key_arr, int numKeys)
{
    int pos = 0;
    while (pos < numKeys && key > key_arr[pos])
    {
        pos++;
    }
    return pos;
}

void inorder(struct Node *ptr)
{
    if (ptr != NULL)
    {
        if (ptr->numKeys >= 1)
        {
            inorder(ptr->children[0]);
            printf("%d ", ptr->keys[0]);
            inorder(ptr->children[1]);
            if (ptr->numKeys == 2)
            {
                printf("%d ", ptr->keys[1]);
                inorder(ptr->children[2]);
            }
        }
    }
}

void display(struct Node *ptr, int blanks)
{
    if (ptr)
    {
        int i;
        for (i = 0; i < ptr->numKeys; i++)
        {
            printf("%d ", ptr->keys[i]);
        }
        printf("\n");
        for (i = 0; i <= ptr->numKeys; i++)
        {
            display(ptr->children[i], blanks + 10);
        }
    }
}
