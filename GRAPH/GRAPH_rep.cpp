#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m; // n-> no of nodes/verteces..... m->no. of edges
    /* vector<int> adj[n + 1];
     for (int i = 0; i < m; i++)
     {
         int u, v;
         cin >> u >> v;
         adj[u].push_back(v);
         adj[v].push_back(u); // it is not valid for directed graph
     }
     */

    // for weighted graph
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // it is not valid for directed graph
    }

    return 0;
}