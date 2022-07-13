#include<bits/stdc++.h>
using namespace std;

typedef unordered_map<int,vector<pair<int,int>> graph;

int main()
{   graph g;
    int n;
    cin>>n;
    int vertex;
    cin>>vertex;
    vector<bool> vis(vertex+1,false);
    int t=n;
    int node1,node2;
    while (t--)
    {   cin>>node1>>node2;
        g[node1].push_back(node2);
    }
    queue<int> q ;
    q.push(5);
    vis[5]=true;
    while(!q.empty())
    {
        int m=q.front();
        q.pop();
        cout<<m<<" ";
        for(int x: g[m])
        {
            if(vis[x]==false)
            {
                vis[x]=true;
                q.push(x);
            }
        }
    }
}
