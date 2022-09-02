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
        bool isValidBST(TreeNode *root)
    {
        long long int val = INT_MIN;
        bool check = true;
        TreeNode *curr = root;
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                if (curr->val < val)
                {
                    check = false;
                }
                val = curr->val;
                curr = curr->right;
            }
            else
            {
                TreeNode *prev = curr->left;
                while (prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }
                if (prev->right == NULL)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    if (curr->val <= val)
                    {
                        check = false;
                    }
                    val = curr->val;
                    curr = curr->right;
                }
            }
        };
        return check;
    }
};

int main()
{
    return 0;
}