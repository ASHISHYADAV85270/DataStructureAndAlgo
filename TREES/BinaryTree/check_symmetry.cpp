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
    bool isSymmetric(TreeNode *root)
    {
        return checkfor_leftand_right(root->left, root->right);
    }
    bool checkfor_leftand_right(TreeNode *rootA, TreeNode *rootB)
    {
        if (rootA == NULL || rootB == NULL)
        {
            return rootA == rootB;
        }
        if (rootA->val != rootB->val)
        {
            return false;
        }
        return checkfor_leftand_right(rootA->left, rootB->right) && checkfor_leftand_right(rootA->right, rootB->left);
    }
};
int main()
{

    return 0;
}
