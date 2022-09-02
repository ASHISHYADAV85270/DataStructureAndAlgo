#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
int maxDepth_recursion(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = maxDepth_recursion(root->left);
    int rh = maxDepth_recursion(root->right);
    return 1 + max(lh, rh);
}

int maxDepth_BFS(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    queue<node *> q;
    int ct = 0;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        ct++;
        while (size--)
        {
            auto it = q.front();
            q.pop();
            if (it->left != NULL)
            {
                q.push(it->left);
            }
            if (it->right != NULL)
            {
                q.push(it->right);
            }
        }
    }
    return ct;
}
int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(5);
    root->left->right = new node(6);
    root->right->left = new node(7);
    root->right->right = new node(8);
    cout << maxDepth_BFS(root) << endl;
    cout << maxDepth_recursion(root);
    return 0;
}