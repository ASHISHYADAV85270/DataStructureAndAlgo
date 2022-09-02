// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
/*
class Solution
{
public:
    // Function to add two numbers represented by linked list.


    Node *reverseLL(Node *head)
    {
        Node *prev_node = NULL;
        Node *curr = head;
        Node *next_node = NULL;
        while (curr != NULL)
        {
            next_node = curr->next;
            curr->next = prev_node;
            prev_node = curr;
            curr = next_node;
        }
        return prev_node;
    }
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        Node *head_first = reverseLL(first);
        Node *head_sec = reverseLL(second);
        Node *final_head = new Node(-1);
        Node *temp = final_head;
        int carry = 0;
        while (head_first != NULL && head_sec != NULL)
        {
            int sum = head_first->data + head_sec->data + carry;
            if (sum > 9)
            {
                carry = 1;
                sum = sum % 10;
            }
            else
            {
                carry = 0;
            }
            Node *curr = new Node(sum);
            temp->next = curr;
            temp = curr;
            head_first = head_first->next;
            head_sec = head_sec->next;
        };
        while (head_first != NULL)
        {
            int sum = head_first->data + carry;
            if (sum > 9)
            {
                carry = 1;
                sum = sum % 10;
            }
            else
            {
                carry = 0;
            }
            Node *curr = new Node(sum);
            temp->next = curr;
            temp = curr;
            head_first = head_first->next;
        };
        while (head_sec != NULL)
        {
            int sum = head_sec->data + carry;
            if (sum > 9)
            {
                carry = 1;
                sum = sum % 10;
            }
            else
            {
                carry = 0;
            }
            Node *curr = new Node(sum);
            temp->next = curr;
            temp = curr;
            head_sec = head_sec->next;
        };
        if (carry == 1)
        {
            Node *curr = new Node(0);
            temp->next = curr;
            temp = curr;
        }

        return reverseLL(final_head->next);
    }

};
*/

class Solution
{
public:
    // Function to add two numbers represented by linked list.

    void *reverseLL(Node *&head)
    {
        Node *prev_node = NULL;
        Node *curr = head;
        Node *next_node = NULL;
        while (curr != NULL)
        {
            next_node = curr->next;
            curr->next = prev_node;
            prev_node = curr;
            curr = next_node;
        }
        head = prev_node;
    }
    void insert_at_tail(Node *&head, Node *&tail, int data)
    {
        Node *curr = new Node(data);
        if (head == NULL)
        {
            tail = curr;
            head = curr;
            return;
        }
        tail->next = curr;
        tail = curr;
    }
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        reverseLL(first);
        reverseLL(second);
        Node *final_head = NULL, *final_tail = NULL;
        int carry = 0;
        while (first != NULL || second != NULL || carry == 1)
        {
            int val_first, val_second;
            if (first != NULL)
            {
                val_first = first->data;
            }
            if (second != NULL)
            {
                val_second = second->data;
            }
            int sum = val_first + val_second + carry;
            if (sum > 9)
            {
                carry = 1;
                sum = sum % 10;
            }
            else
            {
                carry = 0;
            }
            insert_at_tail(final_head, final_tail, sum);
            if (first != NULL)
            {
                first = first->next;
            }
            if (second != NULL)
            {
                second = second->next;
            }
        };
        reverseLL(final_head);
        return final_head;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends