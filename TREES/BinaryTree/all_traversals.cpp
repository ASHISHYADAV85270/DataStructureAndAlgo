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

// phle stack mai daalo looo fir uskoo pop krke check kroo right hai kya fir left because order ulta hita  hai stack mai ...

// preorder mtlb hota hai root left right
/// pre mtlb phle too stack bola hmm too ulta krengai joo krna hai krloo
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
void iter_postorder_by1stack(Node *root)
{
    Node *curr = root;
    stack<Node *> s;
    while (curr != NULL || !s.empty())
    {
        if (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            Node *temp = s.top()->right;
            if (temp == NULL)
            {
                temp = s.top();
                cout << temp->data << " ";
                s.pop();
                while (!s.empty() && temp == s.top()->right)
                {
                    temp = s.top();
                    cout << temp->data << " ";
                    s.pop();
                };
            }
            else
            {
                curr = temp;
            }
        }
    }
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

vector<int> allTraveral(node *root, int x)
{

    // tle---O(3n)
    // space---O(4n)
    if (root == NULL)
    {
        return {};
    }
    stack<pair<node *, int>> s;
    vector<int> pre, in, post;
    s.push({root, 1});
    while (!s.empty())
    {
        auto it = s.top();
        s.pop();

        // if check ==1 then it should be placed in preorder as root(1) left right
        if (it.second == 1)
        {
            pre.push_back(it.first->data);

            // check koo icrement krdoo
            it.second++;

            // element kai second mai ++ krke usai push back kr rhai hai
            s.push(it);

            // left bala null nhi hoga too usai daaldo premai

            if (it.first->left != NULL)
            {
                s.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);

            // check koo increment krdo
            it.second++;

            // element kai second mai ++ krke usai push back krdooo
            s.push(it);

            // right bala check krengai aur agr mila too push back
            if (it.first->right != NULL)
            {
                s.push({it.first->right, 1});
            }
        }
        else
        {
            post.push_back(it.first->data);
        }
    };
    if (x == 1)
    {
        return pre;
    }
    else if (x == 2)
    {
        return in;
    }
    return post;
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
    iter_postorderTraversal_2_stack(root);
    cout << endl;
    iter_postorder_by1stack(root);
    cout << endl;

    // iter_inorderTraversal(root);
    // cout << endl;
    // inorderTraversal(root);
    // cout << endl;
    // breathfirstTraversal(root);
    return 0;
}