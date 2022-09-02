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
    //method 1  tc--O(n)+O(n)  sc--O(n) O(n)
     bool findancestorsfoanode(TreeNode *root, TreeNode *x, vector<TreeNode *> &ans)
     {
         if (root == NULL)
         {
             return false;
         }
         ans.push_back(root);
         if (root == x)
         {
             return true;
         }
         if (findancestorsfoanode(root->left, x, ans) || findancestorsfoanode(root->right, x, ans))
         {
             return true;
         }

         ans.pop_back();
         return false;
     }

     TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
     {
         vector<TreeNode *> v_p;
         bool k = findancestorsfoanode(root, p, v_p);
         vector<TreeNode *> v_q;
         k = findancestorsfoanode(root, q, v_q);
         int size = min(v_p.size(), v_q.size());
         int i = 0;
         for (; i < size; i++)
         {
             if (v_p[i] != v_q[i])
             {
                 break;
             }
         }
         return v_p[i - 1];
     }
     */

    // method2
    //
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL || root == p || root == q)
        {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (right == NULL)
        {
            return left;
        }else if (left == NULL)
        {
            return right;
        }
        // agr dono not null hai too
        return root;
    }
};
int main()
{
    return 0;
}
