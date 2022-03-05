#include<iostream>
#include<string.h>
#include<queue>
#include<utility>
using namespace std;
int N, M, X;
vector<pair<int,int> > adj[1001];
int d[1001];
int visit[1001];

void dijkstra(int start){
    priority_queue<pair<int,int> > pq;
    memset(visit,0,sizeof(visit));
    for(int i=1;i<=N;i++) d[i] = 987654321;
    d[start] = 0;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        int curr = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        for(int j=0;j<adj[curr].size();j++){
            int next = adj[curr][j].first;
            int ncost = adj[curr][j].second;
            if(d[next] > d[curr] + ncost){
                d[next] = d[curr] + ncost;
                pq.push(make_pair(-d[next],next));
            }
        }
    }
}
int main()
{
    cin>>N>>M>>X;
    int st, nd, dist;
    for(int i=0;i<M;i++)
    {
        cin>>st>>nd>>dist;
        adj[st].push_back(make_pair(nd, dist));
    }
    dijkstra(X);
    int max = 0;
    int ans[1001];
    for(int i=1;i<=N;i++){
        ans[i] = d[i];
    }
    for(int i=1;i<=N;i++){
        if(i == X) continue;
        dijkstra(i);
        ans[i] += d[X];
    }
    for(int i=1;i<=N;i++){
        if(max < ans[i]) max = ans[i];
    }
    cout<<max<<endl;
}