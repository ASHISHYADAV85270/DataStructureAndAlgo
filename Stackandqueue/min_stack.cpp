#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
class MinStack
{
    stack<int> st;
    list<int> l;

public:
    MinStack()
    {
    }
    void push(int val)
    {
        if (l.empty())
        {
            l.push_front(val);
        }
        else if (!l.empty() && l.front() >= val)
        {
            l.push_front(val);
        }
        st.push(val);
    }

    void pop()
    {
        int x = st.top();
        if (!l.empty() && l.front() == x)
        {
            l.pop_front();
        }
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return l.front();
    }
};
*/
class MinStack
{
    stack<long long> st;
    long long min_ele;

public:
    MinStack()
    {
        while (!st.empty())
        {
            st.pop();
        };
        min_ele = INT_MAX;
    }
    void push(int val)
    {
        long long value = val;
        if (st.empty())
        {
            min_ele = value;
            st.push(value);
        }
        else
        {
            if (value < min_ele)
            {
                st.push(2 * value * 1LL - min_ele);
                min_ele = value;
            }
            else
            {
                st.push(value);
            }
        }
    }

    void pop()
    {
        if (st.empty())
        {
            return;
        }
        else
        {
            long long value = st.top();
            if (st.top() < min_ele)
            {
                min_ele = 2 * min_ele * 1LL - value;
                st.pop();
            }
            else
            {
                st.pop();
            }
        }
    }

    int top()
    {

        if (st.empty())
        {
            return -1;
        }

        if (st.top() < min_ele)
        {
            return min_ele;
        }
        return st.top();
    }

    int getMin()
    {
        return min_ele;
    }
};
int main()
{
    return 0;
}