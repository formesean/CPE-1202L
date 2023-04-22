#include <stdio.h>
#include <stdlib.h>

#define ORDER 3

typedef struct BTreeNode
{
    int keys[ORDER - 1];
    struct BTreeNode *children[ORDER];
    int num_keys;
    int is_leaf;
} BTreeNode;

BTreeNode *create_node()
{
    BTreeNode *new_node = (BTreeNode *)malloc(sizeof(BTreeNode));
    new_node->num_keys = 0;
    new_node->is_leaf = 1;
    for (int i = 0; i < ORDER; i++)
    {
        new_node->children[i] = NULL;
    }
    return new_node;
}

void insert(BTreeNode **root, int key)
{
    // If the tree is empty, create a new root node
    if (*root == NULL)
    {
        *root = create_node();
        (*root)->keys[0] = key;
        (*root)->num_keys = 1;
        return;
    }

    // Find the appropriate leaf node to insert the key into
    BTreeNode *current_node = *root;
    while (!current_node->is_leaf)
    {
        int i;
        for (i = 0; i < current_node->num_keys; i++)
        {
            if (key < current_node->keys[i])
            {
                break;
            }
        }
        current_node = current_node->children[i];
    }

    // Insert the key into the leaf node
    int i;
    for (i = 0; i < current_node->num_keys; i++)
    {
        if (key < current_node->keys[i])
        {
            break;
        }
    }
    for (int j = current_node->num_keys; j > i; j--)
    {
        current_node->keys[j] = current_node->keys[j - 1];
    }
    current_node->keys[i] = key;
    current_node->num_keys++;

    // If the leaf node is full, split it
    if (current_node->num_keys == ORDER - 1)
    {
        BTreeNode *new_node = create_node();
        new_node->is_leaf = 1;

        // Move the upper median key to the parent node
        int median = (ORDER - 1) / 2;
        int parent_key = current_node->keys[median];
        current_node->num_keys = median;
        new_node->num_keys = ORDER - median - 1;
        for (int j = median + 1; j < ORDER; j++)
        {
            new_node->keys[j - median - 1] = current_node->keys[j];
        }

        // Update the parent node's child pointers
        if (current_node == *root)
        {
            *root = create_node();
            (*root)->keys[0] = parent_key;
            (*root)->children[0] = current_node;
            (*root)->children[1] = new_node;
            (*root)->num_keys = 1;
            current_node->is_leaf = 0;
        }
        else
        {
            BTreeNode *parent_node = *root;
            BTreeNode *current_child = current_node;
            while (parent_node->children[0] != current_child)
            {
                parent_node = parent_node->children[0];
                for (int j = 1; j <= parent_node->num_keys; j++)
                {
                    if (parent_node->children[j] == current_child)
                    {
                        current_child = parent_node->children[j];
                        break;
                    }
                }
            }

            // Shift the parent node's keys and child pointers to make room for the new child
            int i;
            for (i = parent_node->num_keys; i > 0; i--)
            {
                if (parent_key < parent_node->keys[i - 1])
                {
                    parent_node->keys[i] = parent_node->keys[i - 1];
                    parent_node->children[i + 1] = parent_node->children[i];
                }
                else
                {
                    break;
                }
            }
            parent_node->keys[i] = parent_key;
            parent_node->children[i + 1] = new_node;
            parent_node->num_keys++;
            current_node->is_leaf = 0;
        }
    }
}

void inorder_traversal(BTreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    // Traverse all the keys in the left subtree
    inorder_traversal(root->children[0]);
    for (int i = 0; i < root->num_keys; i++)
    {
        printf("%d ", root->keys[i]);
        // Traverse all the keys in the subtree rooted at the i-th child
        inorder_traversal(root->children[i + 1]);
    }
}

int main()
{
    BTreeNode *root = NULL;
    insert(&root, 1);
    insert(&root, 2);
    insert(&root, 3);
    insert(&root, 4);
    insert(&root, 5);
    inorder_traversal(root);
    return 0;
}