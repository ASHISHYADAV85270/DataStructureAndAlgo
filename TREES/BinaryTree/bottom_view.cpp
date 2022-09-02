#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};

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

            m[vertical_level] = temp->data;
        }
        for (auto i : m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }

    vector<int> bottomView(Node *root)
    {
        return verticalTraversal(root);
    }
};
int main()
{
    return 0;
}