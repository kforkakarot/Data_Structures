#include<bits/stdc++.h>
using namespace std;
typedef unordered_map<int,vector<pair<int,int>>> graph;
int main()
{
 graph g;
 g[1].push_back({2,2});
 g[1].push_back({4,1});
 g[2].push_back({1,2});
 g[2].push_back({3,4});
 g[2].push_back({5,5});
 g[3].push_back({2,4});
 g[3].push_back({4,3});
 g[3].push_back({5,1});
 g[4].push_back({1,1});
 g[4].push_back({3,3});
 g[5].push_back({2,5});
 g[5].push_back({3,1});

int source=1;
priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

vector<int> dist(6,INT_MAX);
dist[source]=0;
pq.push({0,source});

while(!pq.empty())
{
    int dis=pq.top().first;
    int node=pq.top().second;
    pq.pop();
    for(auto i:g[node])
    {
        int next=i.first;
        int nextdist=i.second;
        if(dist[next]>dis+nextdist)
        {    dist[next]=dist[node]+nextdist;
            pq.push({dist[next],next});
        }
    }
}

for(int i=1;i<6;i++)
cout<<i<<" "<<dist[i]<<endl;

return 0;
}
