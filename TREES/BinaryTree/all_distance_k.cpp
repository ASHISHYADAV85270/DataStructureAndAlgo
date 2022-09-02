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
    void linkparents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_node)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left)
        {
            parent_node[root->left] = root;
            linkparents(root->left, parent_node);
        }
        if (root->right)
        {
            parent_node[root->right] = root;
            linkparents(root->right, parent_node);
        }
        if (root->left == NULL && root->right == NULL)
        {

            return;
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        // first link children to the parent
        unordered_map<TreeNode *, TreeNode *> parent_node;
        linkparents(root, parent_node);
        int ct = k;

        // start traversal from the target by doing bfs
        queue<TreeNode *> q;
        q.push(target);
        unordered_map<TreeNode *, bool> visited;
        visited[target] = true;
        while (!q.empty() && ct != 0)
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (temp->left && !visited[temp->left])
                {
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if (temp->right && !visited[temp->right])
                {
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                if (parent_node[temp] && !visited[parent_node[temp]])
                {
                    /* code */
                    q.push(parent_node[temp]);
                    visited[parent_node[temp]] = true;
                }
            }
            ct--;
        }
        vector<int> ans;
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            ans.push_back(temp->val);
        }
        return ans;
    }
};
int main()
{
    return 0;
}