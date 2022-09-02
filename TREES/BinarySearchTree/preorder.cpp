#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
    int key;
    struct Node *left, *right;
};

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void traversal(Node *root, Node *&pre, Node *&suc, int key)
{
    if (root == NULL)
    {
        return;
    }
    if (root->key == key)
    {
        if (root->left != NULL)
        {
            pre = root->left;
        }
        if (root->right != NULL)
        {
            suc = root->right;
        }
        return;
    }

    if (root->key < key)
    {
        pre = root;
        traversal(root->right, pre, suc, key);
    }
    else if (root->key > key)
    {
        suc = root;
        traversal(root->left, pre, suc, key);
    }
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{

    pre = NULL;
    suc = NULL;
    traversal(root, pre, suc, key);
}

int main()
{
    return 0;
}