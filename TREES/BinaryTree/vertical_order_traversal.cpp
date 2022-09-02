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
    // bfs lengai aur vertical aur level kai according data set koo rhkengai
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<pair<TreeNode *, pair<int, int>>> q; /// node ,   vertical level , bfs level
        q.push({root, {0, 0}});
        map<int, map<int, multiset<int>>> m;
        while (!q.empty())
        {
            TreeNode *temp = q.front().first;
            int vertical_level = q.front().second.first;
            int bfs_level = q.front().second.second;
            q.pop();
            if (temp->left)
            {
                q.push({temp->left, {vertical_level - 1, bfs_level + 1}});
            }
            if (temp->right)
            {
                q.push({temp->right, {vertical_level + 1, bfs_level + 1}});
            }
            m[vertical_level][bfs_level].insert(temp->val);
        }
        for (auto i : m)
        {
            vector<int> v;
            for (auto j : i.second)
            {
                for (auto k : j.second)
                {
                    v.push_back(k);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};
int main()
{
    return 0;
}
