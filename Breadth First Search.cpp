#include <bits/stdc++.h>
using namespace std;


vector<int>BFS(int v, vector<int> adj[])
{
    vector<int>bfs;
    
    vector<int>vis(v,0);
    
    for(int i=0; i<v; i++)
    {
        if(!vis[i])
        {
            queue<int>q;
            q.push(i);
            vis[i]=1;
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                
                bfs.push_back(node);
                
                for(auto it : adj[node])
                {
                    if(!vis[it])
                    {
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
    }
    return bfs;
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
    vector<int>ans = BFS(n,adj);
    for(auto i: ans)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
	return 0;
}