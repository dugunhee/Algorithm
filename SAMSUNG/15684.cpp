#include<iostream>
#include<algorithm>

using namespace std;
int N,M,H;
int ladder[32][12];
int ans = 987654321;
int play()
{
    int start;
    int tmp;
    for(int i=1;i<=N;i++)
    {
        start=i;
        tmp = i;
        for(int j=1;j<=H;j++)
        {
            if(ladder[j][tmp] == 0) continue;
            else tmp = ladder[j][tmp];
        }
        if(i!=tmp) return 0;
    }
    return 1;
}
void dfs(int x, int y, int cnt)
{
    if(cnt>3) return;
    int i,j;
    int tmpi,tmpj;
    int flag;
    for(i=x;i<=H;i++)
    {
        for(j=1;j<=N-1;j++)
        {
            flag=0;
            if(ladder[i][j] == 0 && ladder[i][j+1] == 0){
                ladder[i][j] = j+1;
                ladder[i][j+1] = j;
                flag = 1;
                if(play() == 1){
                    ans = min(ans,cnt);
                }
                tmpi = i;
                tmpj = j;
            }
            else continue;
            dfs(i,j,cnt+1);
            if(flag == 1){
                ladder[tmpi][tmpj] = 0;
                ladder[tmpi][tmpj+1] = 0;
            }
        }
    }
}
int main()
{
    cin>>N>>M>>H;
    int i,j;
    for(i=1;i<=H;i++)
    {
        for(j=1;j<=N;j++)ladder[i][j] = 0;
    }
    for(i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        ladder[a][b] = b+1;
        ladder[a][b+1] = b;
    }
    if(play() == 1) ans = 0;
    dfs(1,1,1);
    if(ans == 987654321) cout<<-1<<endl;
    else cout<<ans<<endl;
}