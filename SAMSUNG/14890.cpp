#include<iostream>
#include<algorithm>
using namespace std;
int N,L;
int map[101][101];
int scnt=0;
int ans=0;
int main()
{
    cin>>N>>L;
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++) cin>>map[i][j];
    }
    int dflag = 0;
    int fflag = 0;
    for(i=0;i<N;i++)
    {
        scnt = 1;
        fflag = 0;
        dflag = 0;
        for(j=1;j<N;j++)
        {
            if(abs(map[i][j]-map[i][j-1])>1) {//차이 1넘을때
                fflag=1;
                break;
            }
            if(map[i][j] == map[i][j-1]){//같을 때
                scnt++;
                //if(dflag == 1&& j == N-1 && scnt<L) {fflag = 1; break;}
            }
            else if(map[i][j] > map[i][j-1] && scnt>=L){//올라갈 때
                scnt = 1;
            }
            else if(map[i][j] < map[i][j-1] && scnt>=0){
                scnt = -L+1;
            }
            else fflag = 1;
        }
        if(fflag==0 && scnt >= 0) {
            ans++;
        }
    }
    
    int tmpmap[101][101];
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            tmpmap[i][j] = map[i][j];
        }
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            map[i][j] = tmpmap[j][i];
        }
    }for(i=0;i<N;i++)
    {
        scnt = 1;
        fflag = 0;
        dflag = 0;
        for(j=1;j<N;j++)
        {
            if(abs(map[i][j]-map[i][j-1])>1) {//차이 1넘을때
                fflag=1;
                break;
            }
            if(map[i][j] == map[i][j-1]){//같을 때
                scnt++;
                //if(dflag == 1&& j == N-1 && scnt<L) {fflag = 1; break;}
            }
            else if(map[i][j] > map[i][j-1] && scnt>=L){//올라갈 때
                scnt = 1;
            }
            else if(map[i][j] < map[i][j-1] && scnt>=0){
                scnt = -L+1;
            }
            else fflag = 1;
        }
        if(fflag==0 && scnt >= 0) {
            ans++;
        }
    }
    cout<<ans<<endl;
}