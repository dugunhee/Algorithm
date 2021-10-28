#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int board[100][100];
int cb[100][100];
vector<pair<int, int> > virus;
vector< pair< pair<int, int>, int> > tv;
queue<pair<int, int> > q;
int visit[100][100];
int N,M;
int permu[11];
int vcnt;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int ans = 987654321;
int tflag = 0;
void terror(int x, int y)
{
    int i,j;
    int cnt =0;
    visit[x][y] = 1;
    q.push(make_pair(x,y));
    while(!q.empty()){
        int size = q.size();
        cnt++;
        for(i=0;i<size;i++)
        {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            for(j=0;j<4;j++)
            {
                int nx = a + dx[j];
                int ny = b + dy[j];
                if(visit[nx][ny] == 1 || cb[nx][ny] == -1 || nx<0||ny<0 || nx>=N || ny>=N){
                     /*
                     if(tflag == 0 && visit[nx][ny] == 0 && cb[nx][ny] == -2){
                         tv.push_back(make_pair(make_pair(nx,ny),cnt));
                     }*/
                     continue;
                }
                visit[nx][ny] = 1;
                q.push(make_pair(nx,ny));
                if(cb[nx][ny] == -2) continue;
                if(cb[nx][ny]==0) cb[nx][ny] = cnt;
                else{
                    if(cb[nx][ny] > cnt) cb[nx][ny] = cnt;
                }
            }
        }
    }
    while(!q.empty()) q.pop();
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)visit[i][j] = 0;
    }
}
int main()
{
    int i,j;
    vcnt = 0;
    cin>>N>>M;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            visit[i][j] = 0;
            cin>>board[i][j];
            if(board[i][j] == 2) {
                cb[i][j] = -2;
                virus.push_back(make_pair(i,j));
                vcnt++;
            }
            else if(board[i][j] == 1) cb[i][j] = -1;
            else cb[i][j] = 0;
        }
    }
    for(i=0;i<11;i++) permu[i] = 0;
    for(i=0;i<M;i++)permu[i] = 1;
    sort(permu,permu+vcnt);
    do{
        int tmp=0;
        int fflag = 0;
        tflag = 0;
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                if(board[i][j] == 2) cb[i][j] = -2;
                else if(board[i][j] == 1) cb[i][j] = -1;
                else cb[i][j] = 0;
            }
        }
        for(i=0;i<vcnt;i++){
            if(permu[i] == 1){
                //cb[virus[i].first][virus[i].second] = -3;
                terror(virus[i].first,virus[i].second);
            }
        }
        /*
        for(i=0;i<vcnt;i++){
            if(permu[i] == 1){
                terror(virus[i].first,virus[i].second,0);
            }
        }
        cout<<tv.size()<<endl;
        tflag = 1;
        for(i=0;i<tv.size();i++)
        {
            terror(tv[i].first.first,tv[i].first.second,tv[i].second);
        }
        tv.clear();
        */
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                if(cb[i][j] == 0) fflag = 1;
                if(cb[i][j] != -1 && cb[i][j] != -2){
                    tmp = max(tmp,cb[i][j]);
                }
            }
        }
        if(fflag == 1)continue;
        ans = min(ans, tmp);
    }while(next_permutation(permu,permu+vcnt));
    if(ans == 987654321) cout<<-1<<endl;
    else cout<<ans<<endl;
}