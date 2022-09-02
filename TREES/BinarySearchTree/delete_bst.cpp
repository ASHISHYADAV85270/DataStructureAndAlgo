#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};
class Solution
{
public:
    TreeNode *lastr(TreeNode *root)
    {
        if (root->right == NULL)
        {
            return root;
        }
        return lastr(root->right);
    }
    TreeNode *helpme(TreeNode *root)
    {
        if (!root->left)
        {
            return root->right;
        }
        else if (!root->right)
        {
            return root->left;
        }
        TreeNode *curr = root->right;
        TreeNode *lastright_onleftside = lastr(root->left);
        lastright_onleftside->right = curr;
        return root->left;
    }
    // phle position nikal loo uskai parent kii jhaa sai delete krna hai ..fir jis direction mai deletion hai ussi direction mai connection break and bond krna hota hai
    //  jb bhi hmai mile naa joo element delete krna hai too help koo call krdoo
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->val == key)
        {
            return helpme(root);
        }
        TreeNode *curr = root;
        while (root != NULL)
        {
            if (root->val > key)
            {

                if (root->left && root->left->val == key)
                {
                    root->left = helpme(root->left);
                    break;
                }
                else
                {
                    root = root->left;
                }
            }
            else
            {

                if (root->right && root->right->val == key)
                {
                    root->right = helpme(root->right);
                    break;
                }
                else
                {
                    root = root->right;
                }
            }
        };
        return curr;
    }

    // way two
    /*
     TreeNode *lastr(TreeNode *root)
    {
        if (root->left == NULL)
        {
            return root;
        }
        return lastr(root->left);
    }
    TreeNode *helpme(TreeNode *root)
    {
        if (!root->left)
        {
            return root->right;
        }
        else if (!root->right)
        {
            return root->left;
        }
        TreeNode *curr = root->left;
        TreeNode *lastleft_onrightside = lastr(root->right);
        lastleft_onrightside->left = curr;
        return root->right;
    }
    // phle position nikal loo uskai parent kii jhaa sai delete krna hai ..fir jis direction mai deletion hai ussi direction mai connection break and bond krna hota hai
    //  jb bhi hmai mile naa joo element delete krna hai too help koo call krdoo
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->val == key)
        {
            return helpme(root);
        }
        TreeNode *curr = root;
        while (root != NULL)
        {
            if (root->val > key)
            {

                if (root->left && root->left->val == key)
                {
                    root->left = helpme(root->left);
                    break;
                }
                else
                {
                    root = root->left;
                }
            }
            else
            {

                if (root->right && root->right->val == key)
                {
                    root->right = helpme(root->right);
                    break;
                }
                else
                {
                    root = root->right;
                }
            }
        };
        return curr;
    }
    */
};
int main()
{
    return 0;
}