#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool findpath(TreeNode *root, int B, vector<int> &num)
{
    if (root == NULL)
    {
        return false;
    }
    num.push_back(root->val);

    if (root->val == B)
    {
        return true;
    }

    // agr dono taraf nhi hai tooo
    if (findpath(root->left, B, num) || findpath(root->right, B, num))
    {
        return true;
    }

    // joo apnai nhi hotai unhai nikal dena chaiye
    num.pop_back();
    return false;
}
vector<int> solve(TreeNode *A, int B)
{
    vector<int> ans;
    bool k = findpath(A, B, ans);
    return ans;
}
int main()
{
    return 0;
}