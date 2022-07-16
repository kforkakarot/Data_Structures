#include<bits/stdc++.h>
using namespace std;

typedef unordered_map<int,vector<int>> graph;
void dfs(graph g,int n, vector<bool>& vis)
{   vis[n]=true;
    cout<<n<<" ";
    for(int i:g[n])
        if(vis[i]==false)
            dfs(g,i,vis);    
    
}
int main()
{   graph g;
    int edges;
    int vertex;
    cin>>edges;
    cin>>vertex;
    int t=edges;
    while(t--){
        int node1,node2;
        cin>>node1>>node2;
        g[node1].push_back(node2);
    }
    int begin;
    cin>>begin;
    vector<bool> vis(vertex,false);
    dfs(g,begin,vis);
}
