#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M,K;
vector<int> vec[100][100];
int s2d2[101][101];
int soil[101][101];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
int tt[101][101];
void tree(int x,int y)
{
    int i,j;
    for(i=0;i<8;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<N && ny>=0 && ny<N){
            vec[nx][ny].push_back(1);
        }
    }
}
int main()
{
    cin>>N>>M>>K;
    int i,j,k;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++){
            cin>>s2d2[i][j];
            soil[i][j] = 5;
        }
    }
    for(i=0;i<M;i++){
        int x,y,z;
        cin>>x>>y>>z;
        vec[x-1][y-1].push_back(z);
    }
    while(K--){
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++){
                if(vec[i][j].size() == 0)continue;
                sort(vec[i][j].begin(),vec[i][j].end());
                int tx = 0;
                vector<int> tmp;
                for(k=0;k<vec[i][j].size();k++){
                    if(soil[i][j] >= vec[i][j][k]){
                        soil[i][j] -= vec[i][j][k];
                        tmp.push_back(vec[i][j][k]+1);
                    }
                    else{
                        tx += (vec[i][j][k]/2);
                    }
                }
                vec[i][j].clear();
                for(k=0;k<tmp.size();k++) vec[i][j].push_back(tmp[k]);
                soil[i][j] += tx;
            }
        }
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++){
                int size = vec[i][j].size();
                for(k=0;k<size;k++){
                    if(vec[i][j][k] % 5 == 0){
                        tree(i,j);
                    }
                }
            }
        }
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)soil[i][j] += s2d2[i][j];
        }
    }
    int ans=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++){
            ans+=vec[i][j].size();
        }
    }
    cout<<ans<<endl;
}