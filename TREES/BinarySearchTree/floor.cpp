#include <bits/stdc++.h>
#include <iostream>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int floorInBST(TreeNode<int> *root, int X)
{
    TreeNode<int> *curr = root;
    int floor = -1;
    while (curr)
    {
        if (X == curr->val)
        {
            floor = X;
            return floor;
        }
        if (X > curr->val)
        {

            floor = curr->val;
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    return floor;
}
int main()
{
    return 0;
}