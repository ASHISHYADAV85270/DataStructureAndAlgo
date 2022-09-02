#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// it is used when there is non unit weight and undirected graph

int main()
{
    int n, m, w; // n= no of nodes or vertex    m= no of edges  w= weight of edge
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    int src;
    cin >> src;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // pair(distance,node) // minheap pq

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    pq.push({0, src}); // dis ,node
    while (!pq.empty())
    {
        int node = pq.top().second;
        int curr_dis = pq.top().first;
        pq.pop();

        for (auto &val : adj[node])
        {
            int c_node = val.first;
            int d_c_node = val.second;
            if (curr_dis + d_c_node < dist[c_node])
            {
                dist[c_node] = curr_dis + d_c_node;
                pq.push({dist[c_node], c_node});
            }
        }
    };
    for (auto &val : dist)
    {
        cout << val << "   ";
    }

    return 0;
}
