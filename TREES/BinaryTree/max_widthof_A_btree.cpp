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
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<int, TreeNode *>> q;
        q.push({0, root});
        int max_widht = 0;
        while (!q.empty())
        {
            int size = q.size();
            int min_index = q.front().first;
            while (size--)
            {
                TreeNode *temp = q.front().second;
                int curr_index = q.front().first;
                max_widht = max(max_widht, curr_index - min_index + 1);
                q.pop();
                if (temp->left != NULL)
                {
                    q.push({2 * (curr_index - min_index) + 1, temp->left});
                }
                if (temp->right != NULL)
                {
                    q.push({2 * (curr_index - min_index) + 2, temp->right});
                }
            };
        }
        return max_widht;
    }
};
int main()
{
    return 0;
}