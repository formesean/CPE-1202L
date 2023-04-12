// Insertion in Splay Tree

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

// Creates a new node with the given data. Each node has an integer data value,
// initial left and right child pointers to NULL, and returns a pointer to the new node.
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Performs a left rotation (Zig) on the subtree rooted at node x,
// returning the new root of the rotated subtree.
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Performs a right rotation (Zag) on the subtree rooted at node x,
// returning the new root of the rotated subtree.
struct Node *rightRotate(struct Node *x)
{
    struct Node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// Reorganizes the splay tree so that the node with the given data value becomes the new root.
// If the data value is not found in the tree, the last visited node becomes the new root.
// It also performs rotations to maintain the tree's structure.
struct Node *splay(struct Node *root, int data)
{
    if (root == NULL || root->data == data)
        return root;

    if (root->data > data)
    {
        if (root->left == NULL)
            return root;

        if (root->left->data > data)
        {
            // Zig Zig (Left Left)
            root->left->left = splay(root->left->left, data);
            root = rightRotate(root);
        }
        else if (data > root->left->data)
        {
            // Zig Zag (Right Left)
            root->left->right = splay(root->left->right, data);

            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        return (root->left == NULL) ? root : rightRotate(root);
    }
    else
    {
        if (root->right == NULL)
            return root;

        if (data > root->right->data)
        {
            // Zag Zag (Right Right)
            root->right->right = splay(root->right->right, data);
            root = leftRotate(root);
        }
        else if (data < root->right->data)
        {
            // Zag Zig (Left Right)
            root->right->left = splay(root->right->left, data);

            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }

        return (root->right == NULL) ? root : leftRotate(root);
    }
}

// Inserts a new node with the given data value into the splay tree.
// First, it splays the tree based on the data value,
// and then it inserts the new node in the correct position,
// updating the left and right child pointers accordingly.
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    root = splay(root, data);

    if (data < root->data)
    {
        struct Node *newNode = createNode(data);
        newNode->right = root;
        newNode->left = root->left;
        root->left = NULL;
        return newNode;
    }
    else if (data > root->data)
    {
        struct Node *newNode = createNode(data);
        newNode->left = root;
        newNode->right = root->right;
        root->right = NULL;
        return newNode;
    }
    else
        return root;
}

// Deletes a node with the given data value from the splay tree.
// It first splay the tree based on the data value,
// and then it removes the node and adjusts the tree pointers accordingly.
struct Node *delete(struct Node *root, int data)
{
    if (root == NULL)
        return root;

    root = splay(root, data);

    if (data < root->data)
    {
        if (root->left == NULL)
            return root;

        // Zig Zig (Left Left)
        if (data < root->left->data)
        {
            root->left->left = delete (root->left->left, data);
            root = rightRotate(root);
        }
        else if (data > root->left->data)
        {
            // Zig Zag (Right Left)
            root->left->right = delete (root->left->right, data);

            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        return (root->left == NULL) ? root : rightRotate(root);
    }
    else if (data > root->data)
    {
        if (root->right == NULL)
            return root;

        // Zig Zag (Right Left)
        if (data < root->right->data)
        {
            root->right->left = delete (root->right->left, data);

            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        else if (data > root->right->data)
        {
            // Zag Zag (Right Right)
            root->right->right = delete (root->right->right, data);
            root = leftRotate(root);
        }

        return (root->right == NULL) ? root : leftRotate(root);
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }
    return root;
}

// Searches for a node with the given data value in the splay tree.
// It calls the splay() function to find the node and rearrang the tree.
// returning the new root.
struct Node *search(struct Node *root, int data)
{
    return splay(root, data);
}

// Recursively displays the in-order traversal of the splay tree.
// It prints the left subtree, the root node's data, and the right subtree.
void display(struct Node *root)
{
    if (root != NULL)
    {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int main()
{
    struct Node *root = NULL;

    root = insert(root, 15);
    root = insert(root, 7);
    root = insert(root, 25);
    root = insert(root, 1);
    root = insert(root, 11);
    root = insert(root, 30);

    printf("Splay Tree after insertion: ");
    display(root);
    printf("\n");

    int searchElement = 11;
    root = search(root, searchElement);

    printf("\nSplay Tree after searching for %d: ", searchElement);
    display(root);
    printf("\n");

    int deleteElement = 11;
    root = delete (root, deleteElement);

    printf("\nSplay Tree after deletion of %d: ", deleteElement);
    display(root);
    printf("\n");

    return 0;
}