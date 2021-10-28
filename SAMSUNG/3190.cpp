#include<iostream>
#include<queue>
#include<utility>
using namespace std;
queue< pair<int,int> > q;
int board[101][101];
int L[100001]={0,};
int N,K;
int snx, sny, tax ,tay;
int dir;
void shift(int op)
{
    if(dir == 1)
    {
        if(op == 1) dir = 4;
        else if(op == 2) dir = 3;
    }
    else if(dir == 2)
    {
        if(op == 1) dir = 3;
        else if(op == 2) dir = 4;
    }
    else if(dir == 3)
    {
        if(op == 1) dir = 1;
        if(op == 2) dir = 2;
    }
    else
    {
        if(op == 1) dir = 2;
        if(op == 2) dir = 1;
    }
}
int main()
{
    cin>>N;
    cin>>K;
    int i,j;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            board[i][j] = 0;
        }
    }
    board[1][1] = 1;
    for(i=0;i<K;i++)
    {
        int x,y;
        cin>>x>>y;
        board[x][y] = 2;
    }
    int D;
    cin>>D;
    for(i=0;i<D;i++)
    {
        int x;
        char ch;
        cin>>x>>ch;
        if(ch == 'L')L[x] = 1;//left
        else if(ch == 'D') L[x] = 2;//right
    }
    int cnt=1;
    snx = 1;sny = 1;tax = 1;tay = 1;
    int tmpx, tmpy;
    //q.push(make_pair(snx,sny));
    dir = 2;
    for(i=1;;i++)
    {
        tmpx = snx;
        tmpy = sny;
        if(dir == 1) sny--;
        else if(dir == 2)sny++;
        else if(dir == 3)snx--;
        else if(dir == 4)snx++;
        if(board[snx][sny] == 1 || snx<1 || snx>N || sny <1 || sny>N){
            break;
        } 
        if(board[snx][sny] == 2){
            q.push(make_pair(snx,sny));
        }
        else if(board[snx][sny] == 0){
            board[tax][tay] = 0;
            q.push(make_pair(snx,sny));
            tax = q.front().first;
            tay = q.front().second;
            q.pop();
        }
        board[snx][sny] = 1;
        cnt++;
        if(L[i] == 1) shift(1);
        else if(L[i] == 2) shift(2);
    }
    cout<<i<<endl;
}