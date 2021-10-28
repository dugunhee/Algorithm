#include <iostream>
#include <stack>
using namespace std;
stack<int> st;
int N;
int arr[101][101];
int visit[101][101];
int ans;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
void dfs(int x, int y)
{
    visit[x][y] = 1;    
    for(int i=0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 ||nx>N || ny<0 || ny>N || visit[nx][ny] == 1)
        {
            continue;
        }
        dfs(nx,ny);
    }
}
int main()
{
    ans = -1;
    cin >> N;
    int i,j;
    int max = -1;
    int cnt = 0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]> max) max = arr[i][j];
        }
    }
    for(int h=0;h<max;h++)
    {
        cnt = 0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                visit[i][j] = 0;
            }
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(arr[i][j] <= h) visit[i][j] = 1;
            }
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(visit[i][j] == 0) {
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        if(cnt > ans) ans = cnt;
    }
    cout<<ans<<endl;
}