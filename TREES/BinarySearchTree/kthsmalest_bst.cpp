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
    /*
    // it take traversal --O(n) && auxillary space of O(n)
        void inorder(TreeNode *&root, int k, int &val, int &ct)
        {
            if (root == NULL)
            {
                return;
            }
            if (root->left)
            {
                inorder(root->left, k, val, ct);
            }
            ct++;

            if (ct == k)
            {
                val = root->val;
                return;
            }
            if (root->right)
            {
                inorder(root->right, k, val, ct);
            }
        }
        int kthSmallest(TreeNode *root, int k)
        {

            TreeNode *curr = root;
            int val = -1;
            int ct = 0;
            inorder(curr, k, val, ct);
            return val;
        }

        */
    int kthSmallest(TreeNode *root, int k)
    {
        int ct = 0, val = -9;
        TreeNode *temp = root;
        while (temp != NULL)
        {
            if (temp->left == NULL)
            {
                ct++;
                if (ct == k)
                {
                    val = temp->val;
                }
                temp = temp->right;
            }
            else
            {
                TreeNode *prev = temp->left;
                while (prev->right && prev->right != temp)
                {
                    prev = prev->right;
                };
                if (prev->right == NULL)
                {
                    prev->right = temp;
                    temp = temp->left;
                }
                else
                {
                    // prev->right==temp; baali condition
                    prev->right = NULL;
                    ct++;
                    if (ct == k)
                    {
                        val = temp->val;
                    }
                    temp = temp->right;
                }
            }
        };
        return val;
    }
};

int main()
{
    return 0;
}