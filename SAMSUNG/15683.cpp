#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int N,M;
int board[10][10];
int ans=987654321;
vector< pair<int,int> > vec;
void see(int x, int y, int i){
    if(i==0){
        if(x == 0) return;
        while(board[x-1][y] != 6){
            x--;
            if(board[x][y] == 0)board[x][y] = -1;
            if(x<1) break;
        }
    }
    else if(i==1){
        while(board[x][y+1] != 6){
            y++;
           if(board[x][y] == 0)board[x][y] = -1;
           if(y>=M-1) break;
        }
    }
    else if(i==2){
        while(board[x+1][y] != 6){
            x++;
            if(board[x][y] == 0)board[x][y] = -1;
            if(x>=N-1) break;
        }
    }
    else if(i==3){
        if(y==0)return;
        while(board[x][y-1] != 6){
            y--;
            if(board[x][y] == 0)board[x][y] = -1;
            if(y<1) break;
        }
    }
}
void dfs(int num){
    int i,j;
    int x,y;
    int tmp[10][10];
    int cnt=0;
    if(num >= vec.size()){
        for(j=0;j<N;j++)
        {
            for(int k=0;k<M;k++){
                if(board[j][k] == 0)cnt++;
            }
        }
        ans = min(cnt,ans);
        return;
    }
    x = vec[num].first;
    y = vec[num].second;
    for(j=0;j<N;j++)
    {
        for(int k=0;k<M;k++){
            tmp[j][k] = board[j][k];
        }
    }
    for(i=0;i<4;i++){
        if(board[x][y] == 1){
            see(x,y,i);
        }
        else if(board[x][y] == 2){
            see(x,y,i);
            see(x,y,(i+2)%4);
        }
        else if(board[x][y] == 3){
            see(x,y,i);
            see(x,y,(i+1)%4);
        }
        else if(board[x][y] == 4){
            see(x,y,i);
            see(x,y,(i+1)%4);
            see(x,y,(i+2)%4);
        }
        else if(board[x][y] == 5){
            see(x,y,i);
            see(x,y,(i+1)%4);
            see(x,y,(i+2)%4);
            see(x,y,(i+3)%4);
        }
        dfs(num+1);
        for(j=0;j<N;j++)
        {
            for(int k=0;k<M;k++){
              
                board[j][k] = tmp[j][k];
            }
        }
    }
}
int main()
{
    cin>>N>>M;
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            cin>>board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6){
                vec.push_back(make_pair(i,j));
            }
        }
    }
    dfs(0);
    cout<<ans<<endl;
}