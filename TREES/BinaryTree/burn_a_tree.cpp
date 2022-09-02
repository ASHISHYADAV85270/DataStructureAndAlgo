#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void linkChildren(BinaryTreeNode *root, unordered_map<BinaryTreeNode *, BinaryTreeNode *> &parent_node, int start, BinaryTreeNode *&node_pos)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == start)
    {
        node_pos = root;
    }
    if (root->left)
    {
        parent_node[root->left] = root;
        linkChildren(root->left, parent_node, start, node_pos);
    }
    if (root->right)
    {
        parent_node[root->right] = root;
        linkChildren(root->right, parent_node, start, node_pos);
    }
}
int timeToBurnTree(BinaryTreeNode *root, int start)
{
    unordered_map<BinaryTreeNode *, BinaryTreeNode *> parent_node;
    // link the parents with children
    BinaryTreeNode *node_pos = NULL;
    linkChildren(root, parent_node, start, node_pos);

    //
    queue<BinaryTreeNode *> q;
    q.push(node_pos);
    unordered_map<BinaryTreeNode *, bool> visited;
    int ct = 0;

    while (!q.empty())
    {
        int size = q.size();
        ct++;
        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode *temp = q.front();
            q.pop();

            if (temp->left && !visited[temp->left])
            {
                q.push(temp->left);
                visited[root->left] = true;
            }
            if (temp->right && !visited[temp->right])
            {
                q.push(temp->right);
                visited[root->right] = true;
            }
            if (parent_node[temp] && !visited[parent_node[temp]])
            {
                q.push(parent_node[temp]);
                visited[parent_node[temp]] = true;
            }
        }
    }

    return ct;
}

int main()
{
    return 0;
}