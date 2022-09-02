// https://practice.geeksforgeeks.org/problems/twice-counter4236/1
#include <bits/stdc++.h>
#include <iostream>
class Solution
{
public:
    int countWords(string list[], int n)
    {
        unordered_map<string, int> m;
        for (int i = 0; i < n; i++)
        {
            m[list[i]] = m[list[i]] + 1;
        }
        int rep = 0;
        for (auto &it : m)
        {
            if (it.second == 2)
            {
                rep++;
            }
        }
        cout<<rep<<"\n";
    }
};

using namespace std;
int main()
{
string list[10]={"hate","love" ,"peace" ,"love", "peace" ,"hate" ,"love" ,"peace" ,"love", "peace"};
Solution ob;
ob.countWords(list,10);
    return 0;
}