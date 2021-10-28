#include<iostream>
using namespace std;
int N,M;
int visited[1001];
int adj[1001][1001];
void dfs(int vertex)
{
    visited[vertex] = 1;
    int i;
    for(i=1;i<=N;i++)
    {
        if(adj[vertex][i] == 1 && visited[i] == 0) dfs(i);
    }
}
int main()
{
    cin>>N>>M;
    int i,j;
    for(i=1;i<=N;i++)
    {
        visited[i] = 0;
        for(j=1;j<=N;j++)
        {
            adj[i][j] =0;
        }
    }
    for(i=1;i<=M;i++)
    {
        int first,second;
        cin>>first>>second;
        adj[first][second] = 1;
        adj[second][first] = 1;
    }
    int cnt = 0;
    for(i=1;i<=N;i++)
    {
        if(visited[i] == 0){
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt<<endl;
}