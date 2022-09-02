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
int max_height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = max_height(root->left);
    int rh = max_height(root->right);
    return 1 + max(lh, rh);
}

// o(n^2)
int max_dia(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int l_d = max_dia(root->left);
    int r_d = max_dia(root->right);

    int f = max_height(root->left) + max_height(root->right);

    int dia = max(f, max(l_d, r_d));
    return dia;
}

// (n) only height
int cal_h_and_dia(node *root, int &dia)
{
    if (root == NULL)
    {
        return 0;
    }
    int l_h = cal_h_and_dia(root->left, dia);  // left height and update dia
    int r_h = cal_h_and_dia(root->right, dia); // right height and update dia

    int fac = l_h + r_h;
    dia = max(dia, fac);
    return 1 + max(l_h, r_h);
}
int max_dia_optimised(node *root)
{
    int diam = 0;
    int k = cal_h_and_dia(root, diam);
    return diam;
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
    cout << max_dia(root);
    cout << endl;
    cout << max_dia_optimised(root);
    // cout << maxDepth_BFS(root) << endl;
    // cout << maxDepth_recursion(root);
    // cout << max_height(root);
    // int sum = 0;
    // int k = max_diameter(root, sum);
    // cout << sum;
    return 0;
}