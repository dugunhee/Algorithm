#include<iostream>
#include<deque>
#include<string.h>
using namespace std;

deque<int> score[51];
int N,M,T;
int visited[51][51];
int eflag;
void rotate(int idx, int d, int k){
    for(int i=0;i<k;i++){
        if(d == 0){
            int b = score[idx].back();
            score[idx].pop_back();
            score[idx].push_front(b);
        }
        else{
            int f = score[idx].front();
            score[idx].pop_front();
            score[idx].push_back(f);
        }
    }
}
void erase(int x, int y, int st){
    visited[x][y] = 1;
    int nx,ny;
    int sc = score[x][y];
    nx = x;
    ny = y-1;
    int flag = 0;
    if(ny < 0) ny = M-1;
    if(sc!= 0 && visited[nx][ny] == 0 && sc == score[nx][ny]){
        flag = 1;
        erase(nx,ny, flag);
    }
    ny = y+1;
    if(ny == M) ny = 0;
    if(sc!= 0 && visited[nx][ny] == 0 && sc == score[nx][ny]){
        flag = 1;
        erase(nx,ny,flag);
    }
    ny = y;
    nx = x-1;
    if(nx >= 1){
        if(sc!=0&&visited[nx][ny] == 0 && sc == score[nx][ny]){
            flag = 1;
            erase(nx,ny,flag);
        }
    }
    nx = x+1;
    if(nx <= N){
        if(sc!=0&&visited[nx][ny] == 0 && sc == score[nx][ny]){
            flag = 1;
            erase(nx,ny,flag);
        }
    }
    if(flag || st){
        eflag = 1;
        score[x][y] = 0;
    } 
}
int main(){
    cin>>N>>M>>T;
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            int sc;
            cin>>sc;
            score[i].push_back(sc);
        }
    }
    int xi,di,ki;
    while(T--)
    {
        memset(visited,0,sizeof(visited));
        eflag = 0;
        cin>>xi>>di>>ki;
        for(int i=1;i<=N;i++){
            if(i%xi == 0)rotate(i,di,ki);
        }
        double sum = 0;
        for(int i=1;i<=N;i++){
            for(int j=0;j<M;j++){
                if(visited[i][j] == 0)erase(i,j,0);
            }
        }
        int cnt = 0;
        for(int i=1;i<=N;i++){
            for(int j=0;j<M;j++){
                if(score[i][j] != 0){
                    sum += score[i][j];
                    cnt++;
                }
            }
        }
        sum /= cnt;
        if(eflag == 0){
            for(int i=1;i<=N;i++){
                for(int j=0;j<M;j++){
                    if(score[i][j] == 0) continue;
                    if(sum < score[i][j]) score[i][j]--;
                    else if(sum>score[i][j]) score[i][j]++;
                }
            }   
        }
    }
    int ans = 0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            ans += score[i][j];
            //cout<<score[i][j]<<' ';
        }
        // cout<<'\n';
    }
    cout<<ans<<'\n';
}   