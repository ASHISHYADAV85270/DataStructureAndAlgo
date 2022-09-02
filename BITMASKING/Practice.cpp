#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void binaryRepresentation(int num)
{
    for (int i = num; i > 0; i--)
    {
        cout<< ((1<<i) & i);
    }
}
int main()
{
binaryRepresentation(7);
    return 0;
}