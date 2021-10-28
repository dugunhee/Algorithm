#include<iostream>
#include<vector>
using namespace std;
int N;
int adj[101][101];
int visited[101];
int start;
vector<int> ans;
int graph[101][101];
void dfs(int x)
{
    visited[x] = 1;
    int nx;
    int dest;
    for(int i=0;i<N;i++)
    {
        if(adj[x][i] == 1)
        {
            ans.push_back(i);
            if(visited[i] == 1) continue;
            dfs(i);
        }
    }
}
int main()
{
    int i,j;
    cin>>N;
    for(i=0;i<N;i++) visited[i]=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            cin>>adj[i][j];
            graph[i][j] = 0;
        }
    }
    for(i=0;i<N;i++)
    {
        ans.clear();
        for(j=0;j<N;j++)
        {
            visited[j]=0;
        }
        dfs(i);
        for(j=0;j<ans.size();j++)
        {
            graph[i][ans[j]] = 1;
        }
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            cout<<graph[i][j]<<' ';
        }
        cout<<endl;
    }
}