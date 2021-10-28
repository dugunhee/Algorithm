#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M,it;
int graph[100][100];
int visited[100][100];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int cnt;
vector<int> ans;
void dfs(int x, int y)
{
    cnt++;
    visited[x][y] = 1;
    int i;
    int nx,ny;
    for(i=0;i<4;i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if(nx>=0&&nx<N && ny>=0 && ny<M && visited[nx][ny] == 0 && graph[nx][ny] == 0)
        {
            dfs(nx,ny);
        }
    }
}
int main()
{
    cin>>N>>M>>it;
    int i,j,k;
    int x1,x2,y1,y2;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            graph[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    for(i=0;i<it;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        for(j=y1;j<y2;j++)
        {
            for(k=x1;k<x2;k++)
            {
                graph[j][k] = 1;
            }
        }
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            cnt = 0;
            if(visited[i][j] ==0 && graph[i][j] == 0)
            {
                dfs(i,j);
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(i=0;i<ans.size();i++)
    {
        cout<<ans.at(i)<<' ';
    }
}