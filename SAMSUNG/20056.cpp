#include<iostream>
#include<queue>
#include<utility>
using namespace std;
struct fireball{
    int r,c;
    int m;
    int d;
    int s;
};
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
queue<fireball> q[51][51];
int qsize[51][51];
int N,M,K;
void get_qsize(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            qsize[i][j] = q[i][j].size();
            cout<<qsize[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}
pair<int,int> move_dir(int r, int c, int d, int s){
    cout<<"rcds"<<r<<' '<<c<<' '<<d<<' '<<s<<'\n';
    while(s--){
        r += dx[d];
        c += dy[d];
        cout<<r<<' ' <<c<<'\n';
        if(r>N) r = 1;
        else if(r==0) r = N;
        if(c>N) c = 1;
        else if(c==0) c = N;
    }
    return {r,c};
}
void move_fireball(){
    get_qsize();
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=0;k<qsize[i][j];k++){
                fireball fb = q[i][j].front();
                q[i][j].pop();
                pair<int,int> p = move_dir(i,j,fb.d,fb.s);
                int r = p.first;
                int c = p.second;
                //cout<<"r c"<<r<<' '<<c<<'\n';
                q[r][c].push(fb);
            }
        }
    }
}
void split_fireball(){
    get_qsize();
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(qsize[i][j]<2) continue;
            int new_m = 0;
            int new_s = 0;
            int new_d[4]={0,};
            int oddcnt=0, evencnt=0;
            for(int k=0;k<qsize[i][j];k++){
                fireball fb = q[i][j].front();
                q[i][j].pop();
                new_m += fb.m;
                new_s += fb.s;
                if(fb.d%2 == 0) evencnt++;
                if(fb.d%2 == 1) oddcnt++;
            }
            new_m /= 5;
            if(new_m == 0) continue;
            new_s /= qsize[i][j];
            if(evencnt == qsize[i][j] || oddcnt == qsize[i][j]){
                new_d[0] = 0; new_d[1] = 2; new_d[2] = 4; new_d[3] = 6;
            }
            else{
                new_d[0] = 1; new_d[1] = 3; new_d[2] = 5; new_d[3] = 7;
            }
            for(int k=0;k<4;k++){
                fireball fb;
                fb.r = i; fb.c = j;
                fb.d = new_d[k];
                fb.m = new_m;
                fb.s = new_s;
                q[i][j].push(fb);
            }
        }
    }
}

int main()
{
    cin>>N>>M>>K;
    int r,c,m,d,s;
    for(int i=0;i<M;i++){
        cin>>r>>c>>m>>s>>d;
        fireball fb;
        fb.r = r; fb.c = c; fb.m = m; fb.d = d; fb.s = s;
        q[r][c].push(fb);
    }
    while(K--){
        move_fireball();
        split_fireball();
    }
    get_qsize();
    long long ans = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=0;k<qsize[i][j];k++){
                ans += q[i][j].front().m;
                q[i][j].pop();
            }
        }
    }
    cout<<ans<<'\n';
}