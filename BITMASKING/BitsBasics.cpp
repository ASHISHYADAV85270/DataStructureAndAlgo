#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    // 1<<0  means     1----1
    // 1<<1 means      10----2
    // 1<<2 means      100----4
    // 1<<n means      100.....n----2^n
    

    int a= (1<<2);
    cout<<a<<endl;

    int k=(4>>2);//y end sai binary digit remove krdega 
    cout<<k<<endl;

    int b= (1LL<<32) -1;   //iski value different hogi   mtlb -1 hogii...because y range kai bahar chla jaiga ...signed int mai ek bit uska  sign store kai liye hota hai
    cout<<b<<endl;

    cout<<INT32_MAX<<endl;

    unsigned int c=(1LL<<32)-1;
    cout<<c<<"\n";
     return 0;
}