#include<iostream>
#include<queue>
#include<utility>
#include<math.h>
using namespace std;
queue< pair<int, int> > q;
queue< pair<int, int> > q2;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int N,L,R;
int people[100][100];
int visit[100][100];
int sflag;
void bfs(int x, int y){
    visit[x][y] = 1;
    int i,j;
    int cnt = 0;
    int qcnt = 0;
    int tmp = 0;
    q.push(make_pair(x,y));
    q2.push(make_pair(x,y));
    qcnt = 1;
    tmp += people[x][y];
    while(!q.empty()){
        for(i=0;i<q.size();i++)
        {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            for(j=0;j<4;j++){
                int nx = a + dx[j];
                int ny = b + dy[j];
                int res = abs(people[a][b] - people[nx][ny]);
                if(nx<0 || nx>=N || ny<0 || ny>=N || visit[nx][ny] == 1 || res<L || res>R) continue;
                visit[nx][ny] = 1;
                tmp+=people[nx][ny];
                q.push(make_pair(nx,ny));
                q2.push(make_pair(nx,ny));
                qcnt++;
                sflag = 1;
            }
        }
        cnt++;
    }
    tmp /= qcnt;
    while(!q2.empty()){
        int a = q2.front().first;
        int b = q2.front().second;
        people[a][b] = tmp;
        q2.pop();
    }
}
int main()
{
    cin>>N>>L>>R;
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++){
            cin>>people[i][j];
            visit[i][j]=0;
        }
    }
    int ans=0;
    while(1){
        sflag = 0;
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++){
                visit[i][j] =0;
            }
        }
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++){
                if(visit[i][j] == 0){
                    bfs(i,j);
                }
            }
        }
        if(sflag == 1)ans++;
        else break;
    }
    cout<<ans<<endl;
}