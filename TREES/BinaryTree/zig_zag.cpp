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
    // bsf traversal krengai and flag kai according zigzag
    /*
        vector<vector<int>> zigzagLevelOrder(TreeNode *root)
        {
            vector<vector<int>> ans;

            if (root == NULL)
            {
                return ans;
            }

            queue<TreeNode *> q;
            q.push(root);
            int flag = 0;
            while (!q.empty())
            {
                int size = q.size();
                vector<int> v(size);
                for (int i = 0; i < size; i++)
                {
                    TreeNode *temp = q.front();
                    q.pop();
                    if (temp->left != NULL)
                    {
                        q.push(temp->left);
                    }
                    if (temp->right != NULL)
                    {
                        q.push(temp->right);
                    }
                    if (flag % 2 == 0)
                    {
                        v[i] = temp->val;
                    }
                    else
                    {
                        v[size - 1 - i] = temp->val;
                    }
                }
                ans.push_back(v);
                flag++;
            }
            return ans;
        }
        */
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
        {
            return ans;
        }

        queue<TreeNode *> q;
        q.push(root);
        int flag = 0;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> row(size);
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (flag % 2 == 0)
                {
                    row[i] = temp->val;
                }
                else
                {
                    row[size - i - 1] = temp->val;
                }
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            ans.push_back(row);
            flag = 1 - flag;
        };
        return ans;
    }
};
int main()
{
    return 0;
}
