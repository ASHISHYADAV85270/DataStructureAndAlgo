#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    vector<long long> ans;
    queue<long long> v;
    long long int i = 1, j = 1;
    while (j <= N)
    {
        if (A[j] == K)
        {
            v.push(A[j]);
        }
        if (j - i + 1 < K)
        {
            j++;
        }
        else if (j - i + 1 == K)
        {

            if (v.size() != 0)
            {
                ans.push_back(v.front());
            }
            if ((A[i] == v.front()) && (v.size() != 0))
            {
                v.pop();
            }
            i++;
            j++;
        }
    }
    return ans.size();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, count = 0;
        cin >> n;
        long long int m[n];
        map<long long int, int> s;
        for (long long int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            m[i] = x;
            s[x]++;
        }
        for (long long int i = 1; i <= n; i++)
        {
            auto it = s.begin();

            if (it->first == i)
            {
                count = count + printFirstNegativeInteger(m, n, i);
                s.erase(it);
            }
        }
        cout << count << "\n";
    }
    return 0;
}