#include<iostream>
#include<vector>
#include<utility>
#include<string.h>
using namespace std;
vector<pair<int, int> > adj[100001];
int visit[100001]={0,};
int N,ans,len,last;
void dfs(int node){
    visit[node] = 1;
    if(adj[node].size() == 0) return;
    for(int i=0;i<adj[node].size();i++){
        if(visit[adj[node][i].first] == 1)continue;
        len += adj[node][i].second;
        if(ans<len){
            ans = len;
            last = adj[node][i].first;
        }
        dfs(adj[node][i].first);
        len -= adj[node][i].second;
    }
}
int main(){
    cin>>N;
    int st, nd, dist;
    for(int i=0;i<N;i++){
        cin>>st;
        while(1){
            cin>>nd;
            if(nd == -1)break;
            cin>>dist;
            adj[st].push_back(make_pair(nd,dist));
        }
    }
    ans=0;len=0;
    dfs(1);
    memset(visit,0,sizeof(visit));
    len=0;ans=0;
    dfs(last);
    cout<<ans<<endl;
}