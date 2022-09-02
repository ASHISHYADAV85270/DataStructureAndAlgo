#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class QUEUE
{
    stack<int> s1, s2;

public:
    void push_ele(int num)
    {
        while (!s1.empty())
        {
            s2.push(s1.top()); /// s1--> s2
            s1.pop();
        };
        s1.push(num); // x-->s1
        while (!s2.empty())
        {
            s1.push(s2.top()); /// s2--> s1
            s2.pop();
        };
    }
    void pop_ele()
    {
        s1.pop();
    }
    int top_ele()
    {
        return s1.top();
    }
};
int main()
{
    return 0;
}