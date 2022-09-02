// with the help of index
//  #include <bits/stdc++.h>
//  #include <iostream>
//  using namespace std;
//  vector<int> Nextgreater(vector<int> &v)
//  {
//      vector<int> ans(v.size());
//      stack<int> s;
//      for (int i = 0; i < v.size(); i++)
//      {
//          while (!s.empty() && v[i] > v[s.top()])
//          {
//              ans[s.top()] = i;
//              s.pop();
//          };
//          s.push(i);
//      }
//      while (!s.empty())
//      {
//          ans[s.top()] = -1;
//          s.pop();
//      };
//      return ans;
//  }
//  int main()
//  {
//      int n;
//      cin >> n;
//      vector<int> given;
//      for (int i = 0; i < n; i++)
//      {
//          int x;
//          cin >> x;
//          given.push_back(x);
//      }
//      vector<int> ans = Nextgreater(given);
//      for (int i = 0; i < n; i++)
//      {
//          cout << given[i] << " " << (ans[i]==-1? -1 : given[ans[i]]) << "\n";
//      }
//      return 0;
//  }

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void printdata(vector<int> &b)
{
    for (auto &val : b)
    {
        cout << val << " ";
    }
}
void Nextgreater(vector<int> &v)
{
    stack<int> s;
    vector<int> nge(v.size());
    int j = v.size() - 1;
    for (int i = v.size(); i >= 0; i--)
    {
        while (!s.empty() && v[i] >= s.top())
        {
            s.pop();
        }
        if (!s.empty())
        {
            nge[i] = s.top();
        }
        else
        {
            nge[i] = -1;
        }
        s.push(v[i]);
    }
    printdata(nge);
}

int main()
{
    int n;
    cin >> n;
    vector<int> given = {3, 7, 5, 2};
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     given.push_back(x);
    // }
    Nextgreater(given);

    return 0;
}