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
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        queue<TreeNode *> q;
        string str = "";
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (temp == NULL)
                {
                    // string mai special character daaldo
                    str.append("#,");
                }
                else
                {
                    // temp kaa data daaldo
                    str.append(to_string(temp->val) + ',');
                }
                if (temp != NULL)
                {
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
        {
            return NULL;
        }

        stringstream s(data);
        string str;
        getline(s, str, ',');                     // s sai khooo str mai daalde just after , bala data
        TreeNode *root = new TreeNode(stoi(str)); // convert string data to number
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            getline(s, str, ','); // s sai khooo str mai daalde just after , bala data
            if (str == "#")
            {
                temp->left = NULL;
            }
            else
            {
                TreeNode *leftnode = new TreeNode(stoi(str));
                temp->left = leftnode;
                q.push(leftnode);
            }

            getline(s, str, ','); // s sai khooo str mai daalde just after , bala data
            if (str == "#")
            {
                temp->right = NULL;
            }
            else
            {
                TreeNode *rightnode = new TreeNode(stoi(str));
                temp->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
int main()
{
    return 0;
}