#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int sea[101][101];
int dir[101][101];
int speed[101][101];
int R,C,M;
vector< pair<int, int> > shark;
void move()
{
    int i,j;
    int z,s,d;
    vector< pair< int, pair<int, int> > > tmp[101][101];
    for(i=0;i<shark.size();i++)
    {
        int r = shark[i].first;
        int c = shark[i].second;
        z = sea[r][c];
        s = speed[r][c];
        d = dir[r][c];
        int ss = s;
        int rr = r;
        int cc = c;
        if(d == 1 || d == 2){
            while(s--){
                if(r == 1) d=2;
                else if(r == R) d=1;
                if(d==1)r--;
                else if(d==2)r++;
            }
            //cout<<"dir : "<< d << "r c : "<<r<<' '<<c<<endl; 
        }
        else if(d==3 || d == 4){
            while(s--){
                if(c == 1) d=3;
                else if(c == C) d=4;
                if(d==4)c--;
                else if(d==3)c++;
            }
            //cout<<"dir : "<< d << "r c : "<<r<<' '<<c<<endl; 
        }
        tmp[r][c].push_back(make_pair(z,make_pair(ss, d)));
        sea[rr][cc] = 0;
        speed[rr][cc] = 0;
        dir[rr][cc] = 0;
    }
    for(i=1;i<=R;i++)
    {
        for(j=1;j<=C;j++)
        {
            for(int k=0;k<tmp[i][j].size();k++){
                int z = tmp[i][j][k].first;
                int s = tmp[i][j][k].second.first;
                int d = tmp[i][j][k].second.second;
                if(sea[i][j]<z){
                    sea[i][j] = z;
                    speed[i][j] = s;
                    dir[i][j] = d;
                }
            }
            tmp[i][j].clear();
        }
    }
    //shark.clear();
}
int main()
{
    cin>>R>>C>>M;
    int i,j;
    for(i=0;i<=R;i++)
    {
        for(j=0;j<=C;j++){
           sea[i][j] = 0;
        }
    }
    int r,c,s,d,z;
    for(i=0;i<M;i++){
        cin>>r>>c>>s>>d>>z;
        sea[r][c] = z;
        speed[r][c] = s;
        dir[r][c] = d;
        shark.push_back(make_pair(r,c));
    }
    int ans = 0;
    //move();
    
    for(i=1;i<=C;i++)
    {
        for(j=1;j<=R;j++){
            if(sea[j][i]!=0) {
                ans+=sea[j][i];
                speed[j][i] = 0;
                dir[j][i]=0;
                sea[j][i]=0;
                break;
            }
        }
        move();
        shark.clear();
        for(j=1;j<=R;j++){
            for(int k=1;k<=C;k++){
                if(sea[j][k] != 0) shark.push_back(make_pair(j,k));
            }
        }
    }
    cout<<ans<<endl;
}