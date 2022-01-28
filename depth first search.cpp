#include <bits/stdc++.h>
using namespace std;

void dfs_help(int node, vector<int>&vis, vector<int>adj[], vector<int>&dfs)
{
    dfs.push_back(node);
    vis[node]=1;
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            dfs_help(it, vis, adj, dfs);
        }
    }
}

std::vector<int>DFS(int v, vector<int> adj[])
{
    vector<int>dfs;
    vector<int>vis(v,0);
    
    for(int i=0; i<v; i++)
    {
        if(!vis[i])
        {
            dfs_help(i, vis, adj, dfs);
        }
    }
    
    return dfs;
    
    
}
int main() {

    int n, m;
    cin>> n >> m;
    // declare the adjacent matrix
    
    std::vector<int>adj[n+1];
    
    // take edge as input
    
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>ans = DFS(n,adj);
    for(auto i: ans)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
	return 0;
}