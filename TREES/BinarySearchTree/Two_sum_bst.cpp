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
class BST_iterator
{
private:
    stack<TreeNode *> s;
    bool reverse = true;
    void pushAll(TreeNode *node)
    {

        while (node != NULL)
        {
            s.push(node);
            if (reverse == true)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
    }

public:
    BST_iterator(TreeNode *root, bool isreverse)
    {
        reverse = isreverse;
        pushAll(root);
    }
    int next()
    {
        TreeNode *temp = s.top();
        s.pop();
        if (reverse == true)
        {
            pushAll(temp->left);
        }
        else
        {
            pushAll(temp->right);
        }
        return temp->val;
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
        {
            return false;
        }
        BST_iterator value_from_start(root, false);
        BST_iterator value_from_end(root, true);
        int i = value_from_start.next();
        int j = value_from_end.next();
        while (i < j)
        {
            if (i + j == k)
            {
                return true;
            }
            else if (i + j < k)
            {
                i = value_from_start.next();
            }
            else
            {
                j = value_from_end.next();
            }
        }
        return false;
    }
};
int main()
{
    return 0;
}