#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool checkNumber(int x, vector<int> &nums3)
{
    int lo = 0, hi = nums3.size() - 1, mid;
    while (hi >=lo)
    {
        mid = (hi + lo) >> 1;
        if (nums3[mid] == x)
        {
            return true;
        }
        else if (nums3[mid] < x)
        {
            lo = mid+1 ;
        }
        else
        {
            hi = mid ;
        }
    }
    return false;
}
void intersection(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    set<int> s;
    for (int i = 0; i < nums1.size(); i++)
    {
        if (checkNumber(nums1[i], nums2))
        {
            s.insert(nums1[i]);
        }
    }
    vector<int> ans;
    for(auto &val :s)
    {
    //    cout<<val<<" ";
       ans.push_back(val);
    }
    // cout<<endl;
    // for(auto &i: ans)
    // {
    //     cout<<i<<" ";
    // }
    return ans;
   
}
int main()
{
    vector <int> a={25,2,6,63,7,3,4,9,9,4,9,142,1};
    vector <int> b={69,63,4,2,6,9,2,1};
  intersection(a,b);

    return 0;
}