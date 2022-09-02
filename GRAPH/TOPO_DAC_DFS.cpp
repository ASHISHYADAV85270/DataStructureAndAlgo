#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void topo_sort_of_dac(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
{
    vis[node] = 1;
    for (auto &it : adj[node])
    {
        if (!vis[it])
        {
            topo_sort_of_dac(it, vis, adj, st);
        }
    }
    st.push(node);
    // node koo pura traverse krne baad insert krna hai
}
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> topo_ans;
    stack<int> st; // iskaa ulta hi answer hoga topo kaa
    for (int i = 0; i < V; i++)
    {
        topo_sort_of_dac(i, vis, adj, st);
    }

    while (!st.empty())
    {
        topo_ans.push_back(st.top());
        st.pop();
    };
    return topo_ans;
}
int main()
{
    return 0;
}