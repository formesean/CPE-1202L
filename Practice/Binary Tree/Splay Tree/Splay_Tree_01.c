#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
};

struct SplayTree
{
    struct Node *root;
};

struct Node *createNode(int key)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

struct SplayTree *newSplayTree()
{
    struct SplayTree *newSplay = (struct SplayTree *)malloc(sizeof(struct SplayTree));
    newSplay->root = NULL;

    return newSplay;
}

struct Node *maximum(struct SplayTree *tree, struct Node *n)
{
    if (n == NULL)
    {
        return NULL;
    }

    while (n->right != NULL)
    {
        n = n->right;
    }
    return n;
}

void leftRotate(struct SplayTree *tree, struct Node *x)
{
    struct Node *y = x->right;
    x->right = y->left;

    if (y->left != NULL)
    {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NULL)
    {
        tree->root = y;
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void rightRotate(struct SplayTree *tree, struct Node *x)
{
    struct Node *y = x->left;
    x->left = y->right;

    if (y->right != NULL)
    {
        y->right->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NULL)
    {
        tree->root = y;
    }
    else if (x == x->parent->right)
    {
        x->parent->right = y;
    }
    else
    {
        x->parent->left = y;
    }

    y->right = x;
    x->parent = y;
}

void splay(struct SplayTree *tree, struct Node *n)
{
    while (n->parent != NULL)
    {
        if (n->parent == tree->root)
        {
            if (n == n->parent->left)
            {
                rightRotate(tree, n->parent);
            }
            else
            {
                leftRotate(tree, n->parent);
            }
        }
        else
        {
            struct Node *p = n->parent; // parent
            struct Node *grandparent = p->parent;

            if (p->left == n && grandparent->left == p)
            {
                rightRotate(tree, grandparent);
                rightRotate(tree, p);
            }
            else if (p->right == n && grandparent->right == p)
            {
                leftRotate(tree, grandparent);
                leftRotate(tree, p);
            }
            else if (p->right == n && grandparent->left == p)
            {
                leftRotate(tree, p);
                rightRotate(tree, grandparent);
            }
            else if (p->left == n && grandparent->right == p)
            {
                rightRotate(tree, p);
                leftRotate(tree, grandparent);
            }
        }
    }
}

void insert(struct SplayTree *tree, struct Node *n)
{
    struct Node *y = NULL;
    struct Node *temp = tree->root;

    while (temp != NULL)
    {
        y = temp;

        if (n->key < temp->key)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    n->parent = y;

    if (y == NULL)
    {
        tree->root = n;
    }
    else if (n->key < y->key)
    {
        y->left = n;
    }
    else
    {
        y->right = n;
    }

    splay(tree, n);
}

struct Node *search(struct SplayTree *tree, struct Node *n, int item)
{
    if (n == NULL)
    {
        return NULL;
    }

    if (item == n->key)
    {
        splay(tree, n);
        return n;
    }
    else if (item < n->key)
    {
        return search(tree, n->left, item);
    }
    else if (item > n->key)
    {
        return search(tree, n->right, item);
    }
    else
    {
        return NULL;
    }
}

void delete(struct SplayTree *tree, struct Node *n)
{
    splay(tree, n);

    struct SplayTree *leftSubtree = newSplayTree();
    leftSubtree->root = tree->root->left;

    if (leftSubtree->root != NULL)
    {
        leftSubtree->root->parent = NULL;
    }

    struct SplayTree *rightSubtree = newSplayTree();
    rightSubtree->root = tree->root->right;

    if (rightSubtree->root != NULL)
    {
        rightSubtree->root->parent = NULL;
    }

    free(n);

    if (leftSubtree->root != NULL)
    {
        struct Node *m = maximum(leftSubtree, leftSubtree->root);

        splay(tree, m);
        leftSubtree->root->right = rightSubtree->root;
        tree->root = leftSubtree->root;
    }
    else
    {
        tree->root = rightSubtree->root;
    }
}

void inorderTraversal(struct SplayTree *tree, struct Node *n)
{
    if (n != NULL)
    {
        inorderTraversal(tree, n->left);
        printf("%d ", n->key);
        inorderTraversal(tree, n->right);
    }
}

int main()
{
    struct SplayTree *tree = newSplayTree();
    struct Node *n1, *n2, *n3, *n4, *n5;

    n1 = createNode(10);
    insert(tree, n1);

    n2 = createNode(50);
    insert(tree, n2);

    n3 = createNode(11);
    insert(tree, n3);

    // n4 = createNode(21);
    // insert(tree, n4);

    // n5 = createNode(19);
    // insert(tree, n5);

    inorderTraversal(tree, tree->root);

    // int searchKey = 2;

    // struct Node *foundNode = search(tree, tree->root, searchKey);

    // if (foundNode != NULL)
    // {
    //     printf("\nNode with key = %d found\n", foundNode->key);
    // }
    // else
    // {
    //     printf("\nNode with key = %d not found\n", searchKey);
    // }

    // delete (tree, n1);
    // printf("\n");
    // inorderTraversal(tree, tree->root);

    return 0;
}