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
/*
class Solution
{
public:
    // always avoid bfs if possible  bec last node mai bhoot jada nodes hoo jati hai
    // always prefere recursion
    void traversal_with_right_first(TreeNode *root, vector<int> &ans, int level)
    {
        if (root == NULL)
        {
            return;
        }
        if (ans.size() == level)
        {
            ans.push_back(root->val);
        }
        traversal_with_right_first(root->right, ans, level + 1);
        traversal_with_right_first(root->left, ans, level + 1);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        traversal_with_right_first(root, ans, 0);
        return ans;
    }
};
*/
class Solution
{
public:
    void rightview(TreeNode *root, vector<int> &ans, int level)
    {
        if (root == NULL)
        {
            return;
        }
        if (ans.size() == level)
        {
            ans.push_back(root->val);
        }
        rightview(root->right, ans, level + 1);
        rightview(root->left, ans, level + 1);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        rightview(root, ans, 0);
        return ans;
    }

    void left(TreeNode *root, vector<int> &ans, int level)
    {
        if (root == NULL)
        {
            return;
        }
        if (ans.size() == level)
        {
            ans.push_back(root->val);
        }
        rightview(root->left, ans, level + 1);
        rightview(root->right, ans, level + 1);
    }
    vector<int> leftSideView(TreeNode *root)
    {
        vector<int> ans;
        leftSideView(root, ans, 0);
        return ans;
    }
};
int main()
{
    return 0;
}
