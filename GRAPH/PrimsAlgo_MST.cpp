#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
void prims_algo(vector<pair<int, int>> adj[], int n)
{
    // take three vectors

    vector<int> parent(n, -1);
    vector<bool> mst(n, false);
    vector<int> key(n, INT_MAX); // it will store the minimum value in the domain we have traversed

    // let the  starting node is zero only
    parent[0] = -1;
    key[0] = 0;

    // we need total n elements in the mst with n-1 edges --> we dont want circular or cycle in the mst
    for (int ct = 0; ct < n; ct++)
    {

        // it will give tle because it will become n2 ..now we need to improve the loop by using mean heap priority queue
        int min_ele = INT_MAX, u;
        for (int i = 0; i < n; i++)
        {
            if (mst[i] == false && key[i] <= min_ele)
            {
                u = i;
                min_ele = key[i];
            }
        }
        mst[u] = true; // i have taken it in mst

        for (auto &val : adj[u])
        {
            int ele = val.first;
            int wht = val.second;
            if (mst[ele] == false && wht < key[ele])
            {
                key[ele] = wht;
                parent[ele] = u;
            }
        }
    }

    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << " \n";
}
*/
void prims_algo(vector<pair<int, int>> adj[], int n)
{
    // take three vectors

    vector<int> parent(n, -1);
    vector<bool> mst(n, false);
    vector<int> key(n, INT_MAX); // it will store the minimum value in the domain we have traversed

    // let the  starting node is zero only
    parent[0] = -1;
    key[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // key of i (min value of weight)  and index i

    for (int ct = 0; ct < n; ct++)
    {

        int u = pq.top().second;
        pq.pop();
        mst[u] = true; // i have taken it in mst

        for (auto &val : adj[u])
        {
            int ele = val.first;
            int wht = val.second;
            if (mst[ele] == false && wht < key[ele])
            {
                key[ele] = wht;
                parent[ele] = u;
                pq.push({wht, ele});
            }
        }
    }
    //   6 7
    //     0 1 5
    //     0 2 10
    //     0 3 100
    //     1 3 50
    //     1 4 200
    //     3 4 250
    //     4 5 50
    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << " \n";
}
int main()
{
    int n, m, wt;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }
    prims_algo(adj, n);

    return 0;
}