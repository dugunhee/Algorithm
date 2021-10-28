#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int R,C,T;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int board[100][100];
int vu,vd;//vacuum cleaner up,down
vector< pair<int, int> > dustvec;

void clean(int up,int down)
{
    int i,j;
    board[up][0]=0;
    board[down][0]=0;
    for(i=up-1;i>0;i--)
    {
        board[i][0] = board[i-1][0];
    }
    for(j=0;j<C-1;j++){
        board[0][j] = board[0][j+1];
    }
    for(i=0;i<up;i++)
    {
        board[i][C-1] = board[i+1][C-1];
    }
    for(j=C-1;j>0;j--)
    {
        board[up][j] = board[up][j-1];
    }
    for(i=down+1;i<R-1;i++)
    {
        board[i][0] = board[i+1][0];
    }
    for(j=0;j<C-1;j++){
        board[R-1][j] = board[R-1][j+1];
    }
    for(i=R-1;i>down;i--)
    {
        board[i][C-1] = board[i-1][C-1];
    }
    for(j=C-1;j>0;j--)
    {
        board[down][j] = board[down][j-1];
    }
    board[up][0]=-1;
    board[down][0]=-1;
}
int main()
{
    cin>>R>>C>>T;
    int i,j;
    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
        {
            cin>>board[i][j];
            if(board[i][j] == -1){
                vd = i;
                vu = i-1;
            }
        }
    }
    
    int tt[100][100];
    while(T--)
    {
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
            {
                if(board[i][j] > 0){
                    dustvec.push_back(make_pair(i,j));
                }
                tt[i][j] = 0;
            }
        }
        for(i=0;i<dustvec.size();i++)
        {
            int x = dustvec[i].first;
            int y = dustvec[i].second;
            int cnt = 0;
            int amount = board[x][y]/5;
            for(j=0;j<4;j++)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(nx>=0 && nx<R && ny>=0 && ny<C && board[nx][ny] != -1){
                    //board[nx][ny] += amount;
                    tt[nx][ny] += amount;
                    cnt++;
                }
            }
            //board[x][y] = board[x][y] - amount*cnt;
            tt[x][y] -= amount*cnt;
        }
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
            {
                board[i][j] += tt[i][j];
            }
        }
        
        clean(vu,vd);
        dustvec.clear();
    }
    int ans = 0;
    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
        {
            if(board[i][j] >0)ans+= board[i][j];
        }
    }
    cout<<ans<<endl;

}