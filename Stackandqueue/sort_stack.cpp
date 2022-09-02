#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void insert_in_sorted_order(stack<int> &given_Stack, int x)
{

    if (given_Stack.empty() || given_Stack.top() <= x)
    {
        given_Stack.emplace(x);
        return;
    }

    // yeah case 2 hai insertion kaa
    int n = given_Stack.top();
    given_Stack.pop();

    insert_in_sorted_order(given_Stack, x);

    given_Stack.emplace(n);
}
void sortStack(stack<int> &given_Stack)
{
    if (given_Stack.empty())
    {
        return;
    }
    int x = given_Stack.top();
    given_Stack.pop();

    // recursive call for smaller part
    sortStack(given_Stack);

    insert_in_sorted_order(given_Stack, x);
}
int main()
{
    return 0;
}