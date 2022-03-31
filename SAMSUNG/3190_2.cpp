#include<iostream>
#include<deque>
#include<utility>
#include<string.h>
using namespace std;

int board[101][101];
deque<pair<int, int> > deq;
int N, K, L, X;
int x,y;
int dir[4][2] = {
    {2,3},{3,2},{1,0},{0,1}
};
int eflag,cur;
int dx[4] = {0,0,-1,1};//r,l,u,d
int dy[4] = {1,-1,0,0};
int change_dir(int d){
    return dir[cur][d];
}
int move(int t){
    while(1){
        if(X == t){
            break;
        }
        x += dx[cur];
        y += dy[cur];
        if(x<0 || x>=N || y<0 || y>=N) {
            eflag = 1;
            X++;
            break;
        }
        if(board[x][y] == 0){
            int nx,ny;
            board[x][y] = 2;
            deq.push_front(make_pair(x,y));
            nx = deq.back().first;
            ny = deq.back().second;
            board[nx][ny] = 0;
            deq.pop_back();
        }
        else if(board[x][y] == 1){
            deq.push_front(make_pair(x,y));
            board[x][y] = 2;
        }
        else {
            eflag = 1;
            X++;
            break;
        }
        X++;
    }
    return eflag;
}
int main(){
    memset(board,0,sizeof(board));
    cin>>N>>K;
    int ax,ay;
    for(int i=0;i<K;i++){
        cin>>ax>>ay;
        board[ax-1][ay-1] = 1;
    }
    deq.push_back(make_pair(0,0));
    X=0;x=0;y=0;
    board[x][y] = 2;
    cin>>L;
    eflag = 0;
    char c;
    int a,b;
    for(int i=0;i<L;i++){
        cin>>a>>c;
        if(eflag == 1)continue;
        if(c == 'L') b=0;
        else b=1;
        move(a);
        cur = change_dir(b);
    }
    if(eflag == 0){
        move(10000);
    }
    cout<<X<<'\n';
}