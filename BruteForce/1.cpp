#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
queue<pair<int,int> > rq;
queue<pair<int,int> > bq;
int n,m;
int board[10][10];
int visit[10][10];
int ans=987654321;
int redx, redy, bluex, bluey;
int cnt;
int qflag=0;
int move(int rx, int ry, int bx, int by, int op)
{
    int rflag = 0;
    int bflag = 0;
    if(op == 1)//left
    {
        for(int i=1;i<n;i++)
        {
            if(by > ry){
                if(ry>=1 && board[rx][ry-1] == 0)ry--;
                if(board[rx][ry] == 3) rflag = 1;
                if(by>=1 && board[bx][by-1] == 0)by--;
                if(board[rx][ry] == 3) bflag = 1;
                board[bx][by] = 2;
                
            }
            else{
                if(by>=1 && board[bx][by-1] == 0)by--;
                if(board[rx][ry] == 3) bflag = 1;
                if(ry>=1 && board[rx][ry-1] == 0)ry--;
                if(board[rx][ry] == 3) rflag = 1;
            }
            
        }
    }
    else if(op == 2)//up
    {
        for(int i=1;i<n;i++)
        {
            if(bx > rx){
                
                if(rx>=1 && board[rx-1][ry] == 0 )rx--;
                if(board[rx][ry] == 3) rflag = 1;
                if(bx>=1 && board[bx-1][by] == 0 )bx--;
                if(board[rx][ry] == 3) bflag = 1;
                
            }
            else{
                if(bx>=1 && board[bx-1][by] == 0)bx--;
                if(board[rx][ry] == 3) bflag = 1;
                if(rx>=1 && board[rx-1][ry] == 0)rx--;
                if(board[rx][ry] == 3) rflag = 1;
            }
        }
    }
    else if(op == 3)//right
    {
        for(int i=1;i<n;i++)
        {
            if(ry > by){
                
                if(ry<n && board[rx][ry+1] == 0)ry++;
                if(board[rx][ry] == 3) rflag = 1;
                if(by<n && board[bx][by+1] == 0)by++;
                if(board[rx][ry] == 3) bflag = 1;
                
            }
            else{
                if(by<n && board[bx][by+1] == 0)by++;
                if(board[rx][ry] == 3) bflag = 1;
                if(ry<n && board[rx][ry+1] == 0)ry++;
                if(board[rx][ry] == 3) rflag = 1;
            }
        }
    }
    else if(op == 4)//down
    {
        for(int i=1;i<n;i++)
        {
            if(rx > bx){
                
                if(rx<n && board[rx+1][ry] == 0)rx++;
                if(board[rx][ry] == 3) rflag = 1;
                if(bx<n && board[bx+1][by] == 0)bx++;
                if(board[rx][ry] == 3) bflag = 1;
            }
            else{
                if(bx<n && board[bx+1][by] == 0)bx++;
                if(board[rx][ry] == 3) bflag = 1;
                if(ry<n && board[rx+1][ry] == 0)rx++;
                if(board[rx][ry] == 3) rflag = 1;
            }
        }
    }
    redx=rx;redy=ry;bluex=bx;bluey=by;
    if(rflag == 1 && bflag == 0) return 1;
    else return 0;
}
void bfs(int rx, int ry, int bx, int by)
{
    int tmp;
    visit[rx][ry] = 1;
    rq.push(make_pair(rx,ry));
    bq.push(make_pair(bx,by));
    while(!rq.empty())
    {
        int nrx = rq.front().first;
        int nry = rq.front().second;
        int nbx = bq.front().first;
        int nby = bq.front().second;
        rq.pop();
        bq.pop();
        for(int i=1;i<=4;i++)
        {
            tmp = move(nrx,nry,nbx,nby,i);
            if(visit[redx][redy] == 1) continue;
            if(tmp == 1){
                qflag=1;
                ans = max(cnt,ans);
                break;
            }
            rq.push(make_pair(redx, redy));
            bq.push(make_pair(bluex, bluey));
            visit[redx][redy] = 1;
        }
        if(qflag == 1 || cnt>=10) break;
        cnt++;
    }
}
int main()
{
    cin>>n>>m;
    int i,j;
    char ch;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>ch;
            if(ch == '#') board[i][j] = -1;
            else if(ch == '.') board[i][j] = 0;
            else if(ch == 'R') {
                board[i][j] = 0;
                redx = i;
                redy = j;
            }
            else if(ch == 'B'){ 
                board[i][j] = 0;
                bluex=i;
                bluey=j;
            }
            else if(ch == 'O') board[i][j] = 3;
        }
    }
    bfs(redx,redy,bluex,bluey);
    if(cnt==10) cout<<-1<<endl;
    else cout<<ans<<endl;
}