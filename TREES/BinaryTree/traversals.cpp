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
typedef struct node Node;

// DFS depth first search
void preorderTraversal(Node *temp)
{
    if (temp == NULL)
    {
        return;
    }
    cout << temp->data << " ";
    preorderTraversal(temp->left);
    preorderTraversal(temp->right);
}
void iter_preorderTraversal(Node *temp)
{
    if (temp == NULL)
    {
        return;
    }
    stack<Node *> s;
    s.push(temp);
    while (!s.empty())
    {
        Node *curr = s.top();
        s.pop();
        if (curr->right != NULL)
        {
            s.push(curr->right);
        }
        if (curr->left != NULL)
        {
            s.push(curr->left);
        }
        cout << curr->data << " ";
    };
}
void postorderTraversal(Node *temp)
{
    if (temp == NULL)
    {
        return;
    }
    postorderTraversal(temp->left);
    postorderTraversal(temp->right);
    cout << temp->data << " ";
}
void iter_postorderTraversal_2_stack(node *temp)
{
    if (temp == NULL)
    {
        return;
    }
    stack<node *> s_a;
    s_a.push(temp);
    stack<node *> s_b;
    while (!s_a.empty())
    {
        node *curr = s_a.top();
        s_a.pop();
        if (curr->left != NULL)
        {
            s_a.push(curr->left);
        }
        if (curr->right != NULL)
        {
            s_a.push(curr->right);
        }
        s_b.push(curr);
    };
    while (!s_b.empty())
    {
        node *curr = s_b.top();
        s_b.pop();
        cout << curr->data << " ";
    };
}
void inorderTraversal(Node *temp)
{
    if (temp == NULL)
    {
        return;
    }
    inorderTraversal(temp->left);
    cout << temp->data << " ";
    inorderTraversal(temp->right);
}
void iter_inorderTraversal(node *temp)
{
    if (temp == NULL)
    {
        return;
    }
    stack<node *> s;
    node *curr = temp;
    while (true)
    {
        if (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            if (s.empty())
            {
                break;
            }
            curr = s.top();
            s.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}

// breathfirstTraversal
void breathfirstTraversal(Node *temp)
{
    if (temp == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(temp);
    while (!q.empty())
    {
        int len = q.size();
        while (len--)
        {

            node *curr = q.front();
            q.pop();
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
            cout << curr->data << " ";
        };
        cout << "\n";
    };
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
    // iter_preorderTraversal(root);
    // cout << endl;
    // preorderTraversal(root);
    // cout << endl;
    // postorderTraversal(root);
    // cout << endl;
    // iter_postorderTraversal_2_stack(root);
    // iter_inorderTraversal(root);
    // cout << endl;
    // inorderTraversal(root);
    // cout << endl;
    // breathfirstTraversal(root);

    // vector<int> ans = allTraveral(root, 3);
    // for (auto &val : ans)
    // {
    //     cout << val << " ";
    // }
    return 0;
}