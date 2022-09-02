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
    int max_Sum(TreeNode *root, int sum)
    {

        if (root == NULL)
        {
            return sum;
        }
        sum = sum + max_Sum(root->left, sum);
        sum = sum + max_Sum(root->right, sum);

        return root->val + sum;
    }
    int maxPathSum(TreeNode *root)
    {
        return max_Sum(root, 0);
    }
};
int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << s.maxPathSum(root);
    return 0;
}