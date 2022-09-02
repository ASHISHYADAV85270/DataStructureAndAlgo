#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node *traversal(Node *root, Node *x, Node *&successor)
    {
        if (root == NULL)
        {
            return successor;
        }
        if (root->data <= x->data)
        {
            return traversal(root->right, x, successor);
        }
        if (root->data > x->data)
        {
            successor = root;
            return traversal(root->left, x, successor);
        }
    }
    Node *inOrderSuccessor(Node *root, Node *x)
    {
        Node *successor = NULL;
        return traversal(root, x, successor);
    }
};
int main()
{
    return 0;
}