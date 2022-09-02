#include<bits/stdc++.h>
#include<iostream>
using namespace std;
// it should be sorted first of all   they return address
int main()
{ int n=8;
    int a[]={6,2,8,1,9,11,3,5};
    sort(a,a+8);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    //set aur maps kai case mai use krnaa like   s.lower_bound....brna normaly use krogai too boo     O(n) hoga
    // upper bound  joo element hai usai just bdaa brnaa...size+1 kaa addresss
     // lower bound joo element hai   y fir agr boo nhi hoga too just usssai bdaa..y fir size+1 kaa address
  int *p;
  p=lower_bound(a,a+n,6);
  p=lower_bound(a,a+n,4);
  p=upper_bound(a,a+n,11);
  p=upper_bound(a+1,a+3,9);///agr nhi mila too a+3 bala element kaa address
  if(p == a+n)
  {
      cout<<"NOT found";
  }
  else
  {
  cout<<*p;
      
  }

     return 0;
}