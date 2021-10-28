#include<iostream>
#include<vector>
#include<utility>
using namespace std;
typedef struct horse{
    int x;
    int y;
    int dir;//direction
}horse;
vector<horse> status;
//1 right 2 left 3 up 4 down
int board[13][13];
vector<int> location[13][13];
int N,K;
int check()
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(location[i][j].size() >= 4){
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    cin>>N>>K;
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++){
            cin>>board[i][j];
        }
    }
    int x,y,dir;
    for(i=0;i<K;i++)
    {
        cin>>x>>y>>dir;
        horse hor;
        hor.x = x-1;
        hor.y = y-1;
        hor.dir = dir;
        status.push_back(hor);
        location[x-1][y-1].push_back(i);
    }
    int ans = 0;
    int eflag = 0;
    while(1)
    {
        if(ans > 1000){
            ans = -1;
            break;
        }
        ans++;
        for(i=0;i<K;i++)
        {
            int flag = 0;
            x = status[i].x;
            y = status[i].y;
            dir = status[i].dir;
            for(j=0;j<location[x][y].size();j++){
                if(location[x][y][j] == i){
                    flag = j;
                    break;
                }
            }
            int nx = x;
            int ny = y;
            if(status[i].dir == 1)ny++;
            else if(status[i].dir == 2)ny--;
            else if(status[i].dir == 3)nx--;
            else if(status[i].dir == 4)nx++;
            if(nx<0 || nx>=N || ny<0 || ny>=N || board[nx][ny] == 2){
                if(status[i].dir%2 == 0)status[i].dir-=1;
                else status[i].dir+=1;
                nx = x;
                ny = y;
                if(status[i].dir == 1)ny++;
                else if(status[i].dir == 2)ny--;
                else if(status[i].dir == 3)nx--;
                else if(status[i].dir == 4)nx++;
            }
            if(nx<0 || nx>=N || ny<0 || ny>=N || board[nx][ny] == 2){
                continue;
            }
            else if(board[nx][ny] == 0){
                for(j=flag;j<location[x][y].size();j++)
                {
                    location[nx][ny].push_back(location[x][y][j]);
                    status[location[x][y][j]].x = nx;
                    status[location[x][y][j]].y = ny;
                }
                location[x][y].erase(location[x][y].begin()+flag,location[x][y].end());
            }
            else if(board[nx][ny] == 1){
                for(j=location[x][y].size()-1;j>=flag;j--)
                {
                    location[nx][ny].push_back(location[x][y][j]);
                    status[location[x][y][j]].x = nx;
                    status[location[x][y][j]].y = ny;
                }
                location[x][y].erase(location[x][y].begin()+flag,location[x][y].end());
            }
            if(check() == 1){
                cout<<ans<<endl;
                exit(0);
            }
        }
    }
    cout<<ans<<endl;
}