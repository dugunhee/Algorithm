#include<iostream>
#include<queue>
#include<utility>
#include<vector>
#define INF 987654321

using namespace std;

int V,E,K;
vector<pair<int,int> > adj[20001]; 
int d[20001];
void dijkstra(int start)
{
    priority_queue<pair<int,int> > pq;
    for(int i=1;i<=V;i++){
        d[i] = INF;
    }
    d[start] = 0;
    pq.push(make_pair(-d[start],start));
    while(!pq.empty()){
        int curr = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(d[curr] < cost) continue;
        for(int i=0;i<adj[curr].size();i++){
            int next = adj[curr][i].first;
            int dist = adj[curr][i].second;
            if(d[next] > cost + dist){
                d[next] = cost + dist;
                pq.push(make_pair(-d[next],next));
            }
        }
    }
    for(int i=1;i<=V;i++){
        if(d[i] == INF) cout<<"INF"<<'\n';
        else cout<<d[i]<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>V>>E>>K;
    int u,v,w;
    for(int i=0;i<E;i++){
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
    }
    dijkstra(K);
}