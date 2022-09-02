#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
/*
class Solution
{
public:
    vector<int> verticalTraversal(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<pair<Node *, int>> q; /// node ,   vertical level
        q.push({root, 0});
        map<int, int> m; // verticallevel  value
        while (!q.empty())
        {
            Node *temp = q.front().first;
            int vertical_level = q.front().second;
            q.pop();
            if (temp->left)
            {
                q.push({temp->left, vertical_level - 1});
            }
            if (temp->right)
            {
                q.push({temp->right, vertical_level + 1});
            }
            if (m.find(vertical_level) == m.end()) // no repe allowed in vertical
            {

                m[vertical_level] = temp->data;
            }
        }
        for (auto i : m)
        {

            ans.push_back(i.second);
        }
        return ans;
    }

    vector<int> topView(Node *root)
    {
        return verticalTraversal(root);
    }
};
*/
class Solution
{
public:
    vector<int> topView(Node *root)
    {
        // Your code here
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<pair<Node *, int>> q;
        map<int, int> m; // vline temp
        q.push({root, 0});
        while (!q.empty())
        {
            /* code */
            Node *temp = q.front().first;
            int vline = q.front().second;
            q.pop();
            if (m.find(vline) == m.end())
            {
                m[vline] = temp->data;
            }
            if (temp->left != NULL)
            {
                q.push({temp->left, vline - 1});
            }
            if (temp->right != NULL)
            {
                q.push({temp->right, vline + 1});
            }
        };
        for (auto &val : m)
        {
            ans.push_back(val.second);
        }
        return ans;
    }

    // THIS IS FOR BOTTOM PART

    vector<int> bottomView(Node *root)
    {
        // Your Code Here
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<pair<Node *, int>> q;
        map<int, int> m; // vline,node->val
        q.push({root, 0});
        while (!q.empty())
        {
            Node *temp = q.front().first;
            int vline = q.front().second;
            q.pop();
            m[vline] = temp->data;
            if (temp->left)
            {
                q.push({temp->left, vline - 1});
            }
            if (temp->right)
            {
                q.push({temp->right, vline + 1});
            }
        };

        for (auto &val : m)
        {
            ans.push_back(val.second);
        }
        return ans;
    }
};
int main()
{
    return 0;
}