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
    TreeNode *build_sub_tree(vector<int> &inorder, vector<int> &postorder, int instart, int inend, int posstart, int posend, unordered_map<int, int> &m)
    {
        if (instart > inend || posstart > posend)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[posend]);

        int index_of_root_in_inorder = m[root->val];
        int number_before_index_root = index_of_root_in_inorder - instart;

        root->left = build_sub_tree(inorder, postorder, instart, index_of_root_in_inorder - 1, posstart, posstart + number_before_index_root - 1, m);

        root->right = build_sub_tree(inorder, postorder, index_of_root_in_inorder + 1, inend, posstart + number_before_index_root, posend - 1, m);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> m;
        createMap(inorder, m);
        return build_sub_tree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, m);
    }
};
int main()
{

    return 0;
}