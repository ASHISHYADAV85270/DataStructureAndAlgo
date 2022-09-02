#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    int findFloor(vector<long long> v, long long n, long long x)
    {
        long long start = 0, end = n - 1, target = x, res = -1;
        while (start <= end)
        {
            long long mid = start + (end - start) / 2;
            if (v[mid] == target)
            {
                return v[mid];
            }
            else if (v[mid] < target)
            {
                res = v[mid];
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        };
        return res;
    }
    int findFloor(vector<long long> v, long long n, long long x)
    {
        long long start = 0, end = n - 1, target = x, res = -1;
        while (start <= end)
        {
            long long mid = start + (end - start) / 2;
            if (v[mid] == target)
            {
                return v[mid];
            }
            else if (v[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                res = v[mid]; // changing line
                end = mid - 1;
            }
        };
        return res;
    }
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        long long start = 0, end = letters.size() - 1;
        char res = letters[0];
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (letters[mid] == target)
            {
                start = mid + 1;
            }
            else if (letters[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
                res = letters[mid];
            }
        };
        return res;
    }
};

int main()
{

    return 0;
}