#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int N;
string input[25];
int graph[25][25];
int visit[25][25];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,1,-1,0};
int cnt;
vector<int> ans;
void dfs(int x, int y){
    cnt++;
    visit[x][y] = 1;
    int nx,ny;
    for(int i=0;i<4;i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if(nx>=0 && nx<N && ny >=0 && ny<N &&visit[nx][ny] == 0 && graph[nx][ny] == 1){
            dfs(nx,ny);
        }
    }
}
int main()
{
    cin>>N;
    int i,j;
    for(i=0;i<N;i++)
    {
        cin>>input[i];
        for(j=0;j<input[i].length();j++){
            graph[i][j] = input[i].at(j) - 48;
            visit[i][j] = 0;
        }
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(visit[i][j] == 0 && graph[i][j] == 1)
            {
                cnt = 0;
                dfs(i,j);
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
}