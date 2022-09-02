#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int height_of_left_tree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int lh = height_of_left_tree(root->left);
        return 1 + lh;
    }
    int height_of_right_tree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int rh = height_of_right_tree(root->right);
        return 1 + rh;
    }
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left_height = height_of_left_tree(root);
        int right_height = height_of_right_tree(root);
        if (left_height == right_height)
        {
            return pow(2, left_height) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
int main()
{
    return 0;
}