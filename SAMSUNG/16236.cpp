#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
queue<pair<int, int> > q;
vector<pair<int, int> > vec;
int shark_size;
int N;
int table[21][21];
int visit[21][21];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int move_time;
int eat_num;
int eat_flag;
int tmp_time;
void check_visit(int size)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(table[i][j]>size) visit[i][j] = 1;
            else visit[i][j] = 0;
        }
    }
}
int check_finish(int size)
{
    int cnt=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(table[i][j]>=size) cnt++;
            else if(table[i][j] == 0) cnt++;
        }
    }
    if(cnt == N*N) return 1;//finish
    else return 0;
}
void bfs(int x, int y)
{
    table[x][y] = 0;
    visit[x][y] = 1;
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        if(check_finish(shark_size) == 1) break;
        int tmp = q.size();
        move_time++;
        for(int j=0;j<tmp;j++){
            int nx,ny;
            x = q.front().first;
            y = q.front().second;
            visit[x][y] = 1;
            q.pop();
        for(int i=0;i<4;i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            if(visit[nx][ny]==0 && (table[nx][ny]<=shark_size) && nx>=0&&ny>=0&&nx<N&&ny<N)
            {
                q.push(make_pair(nx,ny));
                if(table[nx][ny]!=0 && table[nx][ny]<shark_size)
                {
                    vec.push_back(make_pair(nx,ny));
                }
            }
        }
        }
        if(vec.empty()!=1)
        {
            sort(vec.begin(),vec.end());
            while(!q.empty())
            {
                q.pop();
            }
            q.push(make_pair(vec[0].first,vec[0].second));
            table[vec[0].first][vec[0].second] = 0;
            eat_num++;
            tmp_time = move_time;
            eat_flag = 1;
            if(eat_num == shark_size)
            {
                shark_size++;
                eat_num =0;
            }
            check_visit(shark_size);
            vec.clear();
        }
    
    }
    return;
}
int main()
{
    shark_size = 2;
    move_time=0;
    eat_flag = 0;
    cin>>N;
    int i,j;
    int cnt=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            cin>>table[i][j];
        }
    }
    int x, y;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(table[i][j]>2)
            {
                visit[i][j] = 1;
            }
            else visit[i][j] = 0;
            cnt+=table[i][j];
            if(table[i][j] == 9)
            {
                x=i; y=j;   
            }
        }
    }
    bfs(x,y);
    if(eat_flag == 0)cout<<0<<endl;
    else cout<<tmp_time<<endl;
}