#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
class Solution
{
public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    /*  // level one question
      int isSumProperty(Node *root)
      {
          int child_sum = 0;
          if (root == NULL || (root->left == NULL && root->right == NULL))
          {
              return 1;
          }

          if (root->left != 0)
          {
              child_sum += root->left->data;
          }
          if (root->right != 0)
          {
              child_sum += root->right->data;
          }
          if (child_sum != root->data)
          {
              return 0;
          }
          return isSumProperty(root->left) && isSumProperty(root->right);
      }
      */
    /* void changeTree(Node *root)
     {
         // Write your code here.
         if (root == NULL)
         {
             return;
         }
         long long int child_sum = 0;
         if (root->left != NULL)
         {
             child_sum += root->left->data;
         }
         if (root->right != NULL)
         {
             child_sum += root->right->data;
         }
         if (child_sum > root->data)
         {
             root->data = child_sum;
         }
         else
         {
             if (root->left != NULL)
             {
                 root->left->data = root->data;
             }
             if (root->right != NULL)
             {
                 root->right->data = root->data;
             }
         }

         changeTree(root->left);
         changeTree(root->right);

         long long int total_sum_after_trav = 0;
         if (root->left != NULL)
         {
             total_sum_after_trav += root->left->data;
         }
         if (root->right != NULL)
         {
             total_sum_after_trav += root->right->data;
         }
         if (root->left != NULL || root->right != NULL)
         {
             root->data = total_sum_after_trav;
         }
     }
     */
};
int main()
{
    return 0;
}