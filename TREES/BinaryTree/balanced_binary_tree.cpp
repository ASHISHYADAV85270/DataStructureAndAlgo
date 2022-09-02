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
/// condition for BBT is that   abs(lh-rh)<=1
int maxheight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = maxheight(root->left);
    //  this is another form of dp type mtlb agr ek bhi galat hua toooooooooo ans -1 hoo jaiga
    if (lh == -1)
    {
        return -1;
    }

    int rh = maxheight(root->right);
    if (rh == -1)
    {
        return -1;
    }
    if (abs(lh - rh) > 1)
    {
        return -1;
    }
    return 1 + max(rh, lh);
}
bool isBalanced(node *root)
{
    if (maxheight(root) == -1)
    {
        return false;
    }
    return true;
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
    return 0;
}