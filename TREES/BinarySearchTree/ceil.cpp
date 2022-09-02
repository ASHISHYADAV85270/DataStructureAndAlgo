#include <bits/stdc++.h>
#include <iostream>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

int findCeil(BinaryTreeNode<int> *node, int x)
{
    // Write your code here.
    BinaryTreeNode<int> *curr = node;
    BinaryTreeNode<int> *prev = NULL;
    int ceil = -1;
    while (curr != NULL)
    {
        if (curr->data == x)
        {
            ceil = curr->data;
            return ceil;
        }
        if (x > curr->data)
        {
            curr = curr->right;
        }
        else
        {
            ceil = curr->data;
            curr = curr->left;
        }
    };

    return ceil;
}

int main()
{
    return 0;
}