#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{
    long long int i = 0, j = 0;

    queue<long long> ansq;
    vector<long long> v;
    while (j < N)
    {
        if (A[j] < 0)
        {
            ansq.push(A[j]);
        }
        if (j - i + 1 < K)
        {
            j++;
        }
        else if (j - i + 1 == K)
        {
            if (ansq.size() == 0)
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(ansq.front());
            }
            if (A[i] == ansq.front())
            {
                ansq.pop();
            }
            i++;
            j++;
        }
    }
    return v;
}
int main()
{
    return 0;
}
