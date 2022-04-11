#include<iostream>
#include<string.h>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>
using namespace std;
vector<pair<int, int> > vec;
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
int board[51][51];
queue<int> q[51][51];
int N,M,K;
int fbcnt;
struct fireball{
    int r;
    int c;
    int m;
    int s;
    int d;
    int valid;
} fb[100000];
void move(int idx, int r,int c, int m, int s, int d){
    board[r][c]--;
    q[r][c].pop();
    for(int i=0;i<s;i++){
        r += dx[d];
        c += dy[d];
        if(r<0) r+=N;
        if(c<0) c+=N;
        r %= N;
        c %= N;
    }
    board[r][c]++;
    q[r][c].push(idx);
    fb[idx].r = r;
    fb[idx].c = c;
}
int main()
{
    memset(board,0,sizeof(board));
    cin>>N>>M>>K;
    fbcnt = M;
    for(int i=0;i<M;i++){
        cin>>fb[i].r>>fb[i].c>>fb[i].m>>fb[i].s>>fb[i].d;
        fb[i].r--;
        fb[i].c--;
        board[fb[i].r][fb[i].c] = 1;
        fb[i].valid = 1;
        q[fb[i].r][fb[i].c].push(i);
    }
    for(int x=0;x<K;x++){
        for(int i=0;i<fbcnt;i++){
            if(fb[i].valid == 1)move(i,fb[i].r,fb[i].c,fb[i].m,fb[i].s,fb[i].d);
        }
        
        vec.clear();
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(board[i][j] >= 2){
                    vec.push_back(make_pair(i,j));
                }
            }
        }
        for(int i=0;i<vec.size();i++){
            int msum = 0;
            int ssum = 0;
            int evencnt = 0;
            int oddcnt = 0;
            int size = q[vec[i].first][vec[i].second].size();
            for(int j=0;j<size;j++){
                msum += fb[q[vec[i].first][vec[i].second].front()].m;
                ssum += fb[q[vec[i].first][vec[i].second].front()].s;
                if(fb[q[vec[i].first][vec[i].second].front()].d%2 == 0){
                    evencnt++;
                }
                else oddcnt++;
                fb[q[vec[i].first][vec[i].second].front()].valid = 0;
                q[vec[i].first][vec[i].second].pop();
                board[vec[i].first][vec[i].second]--;
            }
            msum = (msum/5);
            if(msum == 0)continue;
            ssum = (ssum/size);
            for(int k=0;k<4;k++){
                fb[fbcnt+k].r = vec[i].first;
                fb[fbcnt+k].c = vec[i].second;
                fb[fbcnt+k].m = msum;
                fb[fbcnt+k].s = ssum;
                if(oddcnt == size || evencnt == size)fb[fbcnt+k].d = 2*k;
                else fb[fbcnt+k].d = 2*k+1;
                q[vec[i].first][vec[i].second].push(fbcnt+k);
                fb[fbcnt+k].valid = 1;
            }
            fbcnt+=4;
            board[vec[i].first][vec[i].second]+=4;
        }
    }
    int sum = 0;
    for(int i=0;i<fbcnt;i++){
        if(fb[i].valid == 1){
            sum += fb[i].m;
        }
    }
    cout<<sum<<endl;
}