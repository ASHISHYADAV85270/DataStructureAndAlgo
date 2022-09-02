#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void sub_set(string ans, int i, string unused, vector<string> &str_Ans)
{
    if (i == unused.length())
    {
        if (ans == "")
        {
            ans = "$";
        }
        str_Ans.push_back(ans);
        cout << ans << " ";
        return;
    }

    sub_set(ans + unused[i], i + 1, unused, str_Ans);
    sub_set(ans, i + 1, unused, str_Ans);
}
// void sub_set(string ans, int i, string unused)
// {
//     if (i == unused.length())
//     {
//         if (ans == "")
//         {
//             cout << "$";
//         }

//         cout << ans << " ";
//         return;
//     }

//     sub_set(ans + unused[i], i + 1, unused);
//     sub_set(ans, i + 1, unused);
// }
int main()
{
    string s = "abc";
    vector<string> str_Ans = {};
    sub_set("", 0, s, str_Ans);
    cout << "\nok\n";
    for (auto &val : str_Ans)
    {
        cout << val << " ";
    }

    return 0;
}