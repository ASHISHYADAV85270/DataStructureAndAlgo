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
    void flatten(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        TreeNode *curr = root;
        while (curr)
        {
            if (curr->left)
            {
                TreeNode *prev = curr;
                while (prev->right)
                {
                    prev = prev->right;
                };
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        };
        return;
    }
};
int main()
{
    return 0;
}