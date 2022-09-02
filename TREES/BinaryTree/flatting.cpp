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
    // normal using stack
    // void flatten(TreeNode *root)
    // {
    //     stack<TreeNode *> st;
    //     st.push(root);
    //     while (!st.empty())
    //     {
    //         TreeNode *curr = st.top();
    //         st.pop();
    //         if (curr->right)
    //         {
    //             st.push(curr->right);
    //         }
    //         if (curr->left)
    //         {
    //             st.push(curr->left);
    //         }
    //         if (!st.empty())
    //         {
    //             /* code */
    //             curr->right = st.top();
    //         }
    //         curr->left = NULL;
    //     }
    // }

    // by morris traversal
    void flatten(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        TreeNode *curr = root;
        while (curr != NULL)
        {
            if (curr->left != NULL)
            {
                TreeNode *prev = curr->left;
                while (prev->right)
                {
                    prev = prev->right;
                }

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
int main()
{
    return 0;
}