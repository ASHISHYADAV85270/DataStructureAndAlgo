#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class StockSpanner
{
    stack<int> s;
    list<pair<int, int>> l;

public:
    StockSpanner()
    {
        while (!s.empty())
        {
            s.pop();
        }
        while (!l.empty())
        {
            l.pop_back();
        }
    }

    int next(int price)
    {

        int ct = 1;
        while (!l.empty() && price > l.front().first)
        {
            ct = ct + l.front().second;
            l.pop_front();
        };
        l.push_front({price, ct});
        return ct;
    }
};

int main()
{
    return 0;
}