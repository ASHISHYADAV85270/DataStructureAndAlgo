#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// never use complex data structure in unordered sets or maps ...because they use hash technique ///o(1)
//  use complex data structure in ordered sets or maps ...because they use red black technique   //O(logn)

// first last 5
// x x x x x
int main()
{
    map<pair<string, string>, vector<int>> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string fn, ln;
        int no_of_subjects;
        cin >> fn >> ln >> no_of_subjects;
        for (int i = 0; i < no_of_subjects; i++)
        {
            int x;
            cin >> x;
            m[{fn, ln}].push_back(x);
        }
    }
    for (auto &val : m)
    {
        auto &full_name = val.first;
        auto &list_of_marks = val.second;
        cout << "FULL NAME-->" << full_name.first << " " << full_name.second << "\n";
        for (auto &submark : list_of_marks)
        {
            cout << submark << " ";
        }
        cout << endl;
    }

    return 0;
}