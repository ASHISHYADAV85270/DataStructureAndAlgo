#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string skip_theword(string s, int i, string ans, char skip_char)
{
    if (i == s.length())
    {
        return ans;
    }
    if (s[i] != skip_char)
    {
        ans = ans + s[i];
    }
    return skip_theword(s, i + 1, ans, skip_char);
}
int main()
{

    string s = "bafacca";
    cout << skip_theword(s, 0, "", 'a');
    return 0;
}