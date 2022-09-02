#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};
/*
bool isleaf(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    return false;
}

// tc--O(H)  h-->height of tree
void addleftBoundary(Node *root, vector<int> &ans)
{
    // curr koo left jrur krdena brna rep hoo jaiga
    Node *curr = root->left;

    while (curr != NULL)
    {
        if (isleaf(curr) == false)
        {
            ans.push_back(curr->data);
        }
        if (curr->left != NULL)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}
// tc--O(H)  h-->height of tree
void addrightBoundary(Node *root, vector<int> &ans)
{
    Node *curr = root->right;
    vector<int> v;
    while (curr != NULL)
    {
        if (isleaf(curr) == false)
        {
            v.push_back(curr->data);
        }
        if (curr->right != NULL)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        ans.push_back(v[i]);
    }
}

// tc--O(n)
void addleafnodes(Node *root, vector<int> &ans)
{
    if (isleaf(root) == true)
    {
        ans.push_back(root->data);
        return;
    }
    if (root->left != NULL)
    {
        addleafnodes(root->left, ans);
    }
    if (root->right != NULL)
    {
        addleafnodes(root->right, ans);
    }
}
vector<int> boundary(Node *root)
{
    // phle hmlog left baale part koo lengai excluding leaf nodes
    // fir leaf nodes koo add krengai bye preorder traversal
    // fir right vaale part koo ultai order mai lengai excluding lead nodes

    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    // root koo bhi insert krlooo as first data
    if (isleaf(root) == false)
    {
        ans.push_back(root->data);
    }

    // add left bala part
    addleftBoundary(root, ans);

    // addleafenodes by preorder traversals
    addleafnodes(root, ans);

    // add right bala part with reversing
    addrightBoundary(root, ans);
    return ans;
}
*/

int main()
{
    return 0;
}