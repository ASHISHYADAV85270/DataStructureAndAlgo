#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void printBinary(int n)
{
    for (int i = 10; i >= 0; --i)
    {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}

//to check whether it is set or unset
int main()
{
    //   msd           lsd
    //    0 1 0 0 1 0  1

    //set bit --->1
    //unset bit --->0

    printBinary(9);
    int a = 9;
    int i = 0;
    if ((a & (1 << i)) != 0)
    {
        cout << "setbit\n";
    }
    else
    {
        cout << "unsetbit\n";
    }


    /// for setting a bit 
    int k=2;
   printBinary(a | (1<<k) );


   //for unsetting a bit 
   int z=0;
   printBinary(~a); //work like not ..tilda 
//unset
   printBinary( a & (~(1<<z)) );



   //toggle a bit 
   //mtlb particular kaa change krna hai too 
   printBinary( a ^ (1<<2));



cout<<__builtin_popcount(a);
cout<<__builtin_popcountll(a);  //for long type 

   
    return 0;
}