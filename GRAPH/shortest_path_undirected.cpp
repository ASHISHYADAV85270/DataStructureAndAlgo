#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    void shortestPathLength(vector<vector<int>> &graph, int n, int scr)
    {
        int distance[n];
        // first we have to create a array having maximum values
        for (int i = 0; i < n; i++)
        {
            distance[i] = INT_MAX;
        }
        queue<int> q;
        // initialise q zero as 0

        q.push(scr);
        distance[scr] = 0;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (auto &it : graph[x])
            {
                // joo current value hai usai hmm compare kr rhai hai uskai childs sai kiii uskaaa distance +1  < child ka phle bala distance
                if (distance[x] + 1 < distance[it])
                {
                    distance[it] = distance[x] + 1;
                    q.push(it);
                }
            }
        };
        for (int i = 0; i < n; i++)
        {
            cout << distance[i] << "  ";
        }
    }
};
int main()
{
    vector<vector<int>> graph = {{1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2}};
    Solution s;
    s.shortestPathLength(graph, 5, 0);
    return 0;
}