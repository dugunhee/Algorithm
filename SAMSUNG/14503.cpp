#include<iostream>

using namespace std;
int N,M;
//int dir;
int board[51][51];
int visit[51][51];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int ans = 1;
void clean(int r, int c,int dir)
{
    //visit[r][c] = 1;
    //ans++;
    int cnt = 0;
    //cout<<"r and c: "<<r<<' '<<c<<endl;
    //cout<<ans<<endl;
    for(int i=0;i<4;i++)
    {
        int nx = r;
        int ny = c;
        if(dir == 0)ny--;
        else if(dir == 1)nx--;
        else if(dir == 2)ny++;
        else if(dir == 3)nx++;
        dir = (dir+3)%4;
        if(visit[nx][ny] == 1 || board[nx][ny] == 1){
            cnt++;
        }
        else if(visit[nx][ny] == 0 && board[nx][ny] == 0){
            visit[nx][ny] = 1;
            ans++;
            clean(nx,ny,dir);
        }
    }
    if(cnt==4){
        if(dir == 0){
            if(board[r+1][c] == 1){
                cout<<ans<<endl;
                exit(0);
            }
            r++;
        }
        else if(dir == 1){
            if(board[r][c-1] == 1){
                cout<<ans<<endl;
                exit(0);
            }
            c--;
        }
        else if(dir == 2){
            if(board[r-1][c] == 1)
            {
                cout<<ans<<endl;
                exit(0);
            }
            r--;
        }
        else if(dir == 3){
            if(board[r][c+1] == 1){
                cout<<ans<<endl;
                exit(0);
            }
            c++;
        }
        clean(r,c,dir);
    }
}
int main()
{
    int r,c,i,j,d;
    cin>>N>>M;
    cin>>r>>c>>d;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            cin>>board[i][j];
            visit[i][j] = 0;
        }
    }
    visit[r][c] = 1;
    clean(r,c,d);
}