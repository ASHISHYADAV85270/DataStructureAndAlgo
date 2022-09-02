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
    TreeNode *bst_Tree_from_prerderand_inorder(vector<int> inorder, int instart, int inend, vector<int> preorder, int prestart, int preend, unordered_map<int, int> &m)
    {
        if (prestart > preend || instart > inend)
        {
            return NULL;
        }

        int index_of_curr_eleininorder = m[preorder[prestart]];
        int number_ofEleBeforeCurr = index_of_curr_eleininorder - instart;

        TreeNode *root = new TreeNode(preorder[prestart]);
        root->left = bst_Tree_from_prerderand_inorder(inorder, instart, index_of_curr_eleininorder - 1, preorder, prestart + 1, prestart + number_ofEleBeforeCurr, m);
        root->right = bst_Tree_from_prerderand_inorder(inorder, index_of_curr_eleininorder + 1, inend, preorder, prestart + number_ofEleBeforeCurr + 1, preend, m);

        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); i++)
        {
            /* code */
            m[inorder[i]] = i;
        }
        return bst_Tree_from_prerderand_inorder(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1, m);
    }
};
int main()
{
    return 0;
}