#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
int N,E;
int INF = 987654321;
vector<pair<int,int> > adj[1000]; 
int d[1000];
void dijkstra(int start){
    for(int i=0;i<=N;i++){
        d[i] = INF;
    }
    d[start] = 0;
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        int cost = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        for(int i=0;i<adj[curr].size();i++){
            int next = adj[curr][i].first;
            int ncost = adj[curr][i].second;
            if(d[next] > d[curr] + ncost){
                d[next] = d[curr] + ncost;
                pq.push(make_pair(-d[next],next));
            }
        }
    }
}
int main()
{
    cin>>N>>E;
    int st, nd, dist;
    for(int i=0;i<E;i++){
        cin>>st>>nd>>dist;
        adj[st].push_back(make_pair(nd,dist));
        adj[nd].push_back(make_pair(st,dist));
    }
    int v1, v2;
    cin>>v1>>v2;
    dijkstra(v1);
    int ans[5], flag=0;
    ans[0] = d[v2];//v1->v2
    if(d[v2] == INF) flag = 1;
    dijkstra(1);
    ans[1] = d[v1];//1->v1
    ans[2] = d[v2];//1->v2
    if(d[v1] == INF && d[v2] == INF){
        flag = 1;
    }
    int st1=d[v1], st2=d[v2];
    dijkstra(N);
    ans[3] = d[v1];//N->v1;
    ans[4] = d[v2];//N->v2;
    if(d[v1] == INF && d[v2] == INF){
        flag = 1;
    }
    int nd1=d[v1], nd2=d[v2];
    int len = ans[0];
    len += min(ans[1] + ans[4], ans[2] + ans[3]);
    if(flag == 1) cout<<-1<<endl;
    else cout<<len<<endl;
}


/*
1->v1->v2->N
N->v1->v2->1
*/