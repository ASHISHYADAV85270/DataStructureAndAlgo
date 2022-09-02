#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// USING  COUPLE OF QUEUE
queue<int> q1, q2;
void push_ele(int num)
{
    q2.push(num);
    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    };
    swap(q1, q2);
}

void pop_ele()
{
    q1.pop();
}
int top_ele()
{
    return q1.front();
}

// using one queue
class Stack
{
    queue<int> q;

public:
    void Push(int x)
    {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++)
        {

            q.push(q.front());
            q.pop();
        }
    }
    int Pop()
    {
        int n = q.front();
        q.pop();
        return n;
    }
    int Top()
    {
        return q.front();
    }
    int Size()
    {
        return q.size();
    }
};
int main()
{
    return 0;
}