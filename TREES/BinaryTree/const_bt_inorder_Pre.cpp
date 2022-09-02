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
    void createMap(vector<int> &inorder, unordered_map<int, int> &m)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }
    }
    TreeNode *build_sub_tree(vector<int> &inorder, vector<int> &preorder, int instart, int inend, int prestart, int preend, unordered_map<int, int> &m)
    {
        if (instart > inend || prestart > preend)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[prestart]);

        int index_of_root_in_inorder = m[root->val];
        int number_before_index_root = index_of_root_in_inorder - instart;
        root->left = build_sub_tree(inorder, preorder, instart, index_of_root_in_inorder - 1, prestart + 1, prestart + number_before_index_root, m);
        root->right = build_sub_tree(inorder, preorder, index_of_root_in_inorder + 1, inend, prestart + number_before_index_root + 1, preend, m);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> m;
        createMap(inorder, m);
        return build_sub_tree(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1, m);
    }
};
int main()
{
    Solution s;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *root = s.buildTree(preorder, inorder);
    cout << root->right->left->val;
    return 0;
}