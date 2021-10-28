#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
int arr[100][100];
int visit[100][100];
int dist[100][100];
int N,M;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
vector< pair<int, int> > vec;
vector< pair<int, int> > one;
int a[13];
queue< pair<int, int> > q;
void bfs(int x, int y)
{
    int cnt = 1;
    visit[x][y] = 1;
    q.push(make_pair(x,y));
    while(!q.empty()){
        int size = q.size();
        for(int j=0;j<size;j++){
            int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if(nx<0 || nx>=N || ny<0 || ny>=N || visit[nx][ny] == 1) continue;
            else{
                visit[nx][ny] = 1;
                q.push(make_pair(nx,ny));
                if(arr[nx][ny] == 1){
                    dist[nx][ny] = min(dist[nx][ny],abs(x-nx)+abs(y-ny));
                }
            }
        }
        }
        cnt++;
    }
}
int main()
{
    cin>>N>>M;
    int i,j;
    int tcnt=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j] == 2) {
                vec.push_back(make_pair(i,j));
                tcnt++;
            }
            else if(arr[i][j] == 1) one.push_back(make_pair(i,j));
            visit[i][j]=0;
            dist[i][j] = 9999999;
        }
    }
    for(i=0;i<M;i++)
    {
        a[i] = 1;
    }
    sort(a,a+tcnt);
    int ans = 987654321;
    do{
        int tmp = 0;
        for(i=0;i<N;i++){
            for(j=0;j<N;j++)dist[i][j] = 9999999;
        }
        for(i=0;i<tcnt;i++)
        {
            if(a[i] == 1){
                for(j=0;j<N;j++){
                    for(int k=0;k<N;k++)visit[j][k] = 0;
                }
                bfs(vec[i].first,vec[i].second);
            }
        }
        for(i=0;i<one.size();i++)
        {
            tmp += dist[one[i].first][one[i].second];
        }
        ans = min(tmp,ans);
    }while(next_permutation(a,a+tcnt));
    cout<<ans<<endl;
}