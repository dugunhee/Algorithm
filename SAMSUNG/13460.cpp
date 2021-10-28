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
        for(int i=1;i<10;i++)
        {
            if(by > ry){
                if(ry>1 && board[rx][ry-1] != -1)ry--;
                if(board[rx][ry] == 3) rflag = 1;
                if(board[bx][by-1] == 3) bflag = 1;
                if((rx!=bx || ry!= by-1) && by>1 && board[bx][by-1] != -1)by--;
            }
            else{
                if(by>1 && board[bx][by-1] != -1)by--;
                if(board[bx][by] == 3) bflag = 1;
                if(board[rx][ry-1] == 3) rflag = 1;
                if((rx!=bx || by!= ry-1) && ry>1 && board[rx][ry-1] != -1)ry--;
            }
        }
    }
    else if(op == 2)//up
    {
        for(int i=1;i<10;i++)
        {
            if(bx > rx){
                
                if(rx>1 && board[rx-1][ry] != -1 )rx--;
                if(board[rx][ry] == 3) rflag = 1;
                if(board[bx-1][by] == 3) bflag = 1;
                if((ry!=by || rx!=bx-1) && bx>1 && board[bx-1][by] != -1 )bx--;
            }
            else{
                if(bx>1 && board[bx-1][by] != -1)bx--;
                if(board[bx][by] == 3) bflag = 1;
                if(board[rx-1][ry] == 3) rflag = 1;
                if((ry!=by || bx!=rx-1) && rx>1 && board[rx-1][ry] != -1)rx--;
                
            }
        }
    }
    else if(op == 3)//right
    {
        for(int i=1;i<10;i++)
        {
            if(ry > by){
                
                if(ry<m-1 && board[rx][ry+1] != -1)ry++;
                if(board[rx][ry] == 3) rflag = 1;
                if(board[bx][by+1] == 3) bflag = 1;
                if((ry!=by+1 || bx!=rx) && by<m-1 && board[bx][by+1] != -1)by++;
                
            }
            else{
                if(by<m-1 && board[bx][by+1] != -1)by++;
                if(board[bx][by] == 3) bflag = 1;
                if(board[rx][ry+1] == 3) rflag = 1;
                if((by!=ry+1 || bx!=rx) && ry<m-1 && board[rx][ry+1] != -1)ry++;
            }
        }
    }
    else if(op == 4)//down
    {
        for(int i=1;i<10;i++)
        {
            if(rx > bx){
                
                if(rx<n-1 && board[rx+1][ry] != -1)rx++;
                if(board[rx][ry] == 3) rflag = 1;
                if(board[bx+1][by] == 3) bflag = 1;
                if((by!=ry || rx!= bx+1) && bx<n-1 && board[bx+1][by] != -1)bx++;
            }
            else{
                if(bx<n-1 && board[bx+1][by] != -1)bx++;
                if(board[bx][by] == 3) bflag = 1;
                if(board[rx+1][ry] == 3) rflag = 1;
                if((by!=ry || bx!= rx+1) && rx<n-1 && board[rx+1][ry] != -1)rx++;
            }
        }
    }
    redx=rx;redy=ry;bluex=bx;bluey=by;
    if(rflag == 1 && bflag == 0) return 1;
    else if(bflag == 1) return 2;
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
        int size = rq.size();
        cnt++;
        for(int k=0;k<size;k++){
            int nrx = rq.front().first;
        int nry = rq.front().second;
        int nbx = bq.front().first;
        int nby = bq.front().second;
        rq.pop();
        bq.pop();
        for(int i=1;i<=4;i++)
        {
            tmp = move(nrx,nry,nbx,nby,i);
            if(tmp == 1){
                qflag=1;
                break;
            }
            else if(tmp == 2) continue;
            rq.push(make_pair(redx, redy));
            bq.push(make_pair(bluex, bluey));
        }
        if(qflag == 1 || cnt>10) {
            while(!rq.empty()) rq.pop();
            break;
        }
        }
    }
}
int main()
{
    cin>>n>>m;
    int i,j;
    char ch;
    cnt=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
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
    if(cnt>10) cout<<-1<<endl;
    else cout<<cnt<<endl;
}