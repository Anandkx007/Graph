#include <bits/stdc++.h>
using namespace std;

bool check_for_cycle(int node,int prev,vector<int>adj[],vector<int>&vis)
{
    vis[node]=1;
    
    for(auto it: adj[node])
    {
        if(vis[it]==0)
        {
            if(check_for_cycle(it, node, adj, vis))return true;
        }
        else if( it != prev) return true;
        
    }
    return false;
    
}

bool isCycle(int n, vector<int> adj[])
{
    vector<int>vis(n,0);
    
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            if(check_for_cycle(i,n,adj,vis))
            {
                return true;
            }
        }
    }
    return false;
    
    
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
    
    cout<<isCycle(n,adj);
    
	return 0;
}