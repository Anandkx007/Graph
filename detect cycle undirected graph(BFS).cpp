#include <bits/stdc++.h>
using namespace std;

bool check_for_cycle(int node,int v,vector<int>adj[],vector<int>&vis)
{
    std::queue<pair<int,int>>qp;
    
    vis[node]=1;
    
    qp.push({node, -1});
    
    while(!qp.empty())
    {
        int node = qp.front().first;
        int prev = qp.front().second;
        qp.pop();
        
        for( auto it : adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                qp.push({it, node});
            }
            else if(prev != it)
            {
                return true;
            }
        }
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