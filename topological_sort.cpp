#include<bits/stdc++.h>
using namespace std;
//topological sort Khan's Algo
typedef unordered_map<int, vector<int>> graph;
void topological(graph g, vector<int>& indegree)
{
    queue<int> q;
    for(int i=0;i<indegree.size();i++)
        if(indegree[i]==0)
            q.push(i);
            
    while(!q.empty())
    {
        int n=q.front();
        q.pop();
        cout<<n<<" ";
        for(auto x:g[n])
        {
            indegree[x]-=1;
            if(indegree[x]==0)
                q.push(x);
        }
    }
}
int main()
{   graph g;
    int edges,vertex;
    cin>>vertex;
    int node1,node2,weight;
    vector<int> indegree(vertex,0);
    cin>>edges;
    int t=edges;
    while(t--)
    {
        cin>>node1>>node2;
        g[node1].push_back(node2);
        indegree[node2]+=1;
    }
    topological(g,indegree);
    
    
}
