#include<iostream>
#include<vector>
#include<utility>

using namespace std;
int INF = 987654321;
int T,N,M,W;
vector<pair<int,int> > adj[501];
int d[501];
bool bellman(int start){
    for(int i=1;i<=500;i++){
        d[i] = INF;
    }
    d[start] = 0;
    bool flag = false;
    for(int i=1;i<=N;i++){
        flag = false;
        for(int j=1;j<=N;j++){
            for(int k=0;k<adj[j].size();k++){
                int next = adj[j][k].first;
                int cost = adj[j][k].second;
                if(d[next] > d[j] + cost){
                    d[next] = d[j] + cost;
                    flag = true;
                }
            }
        }
        if(flag == false) break;
    }
    return flag;
}
int main(){
    cin>>T;
    while(T--){
        for(int i=0;i<501;i++){
            adj[i].clear();
            d[i] = INF;
        }
        cin>>N>>M>>W;
        int S,E,T;
        for(int i=0;i<M;i++){
            cin>>S>>E>>T;
            adj[S].push_back(make_pair(E,T));
            adj[E].push_back(make_pair(S,T));
        }
        for(int i=0;i<W;i++){
            cin>>S>>E>>T;
            adj[S].push_back(make_pair(E,-T));
        }
        if(bellman(1) == true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}