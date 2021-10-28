#include<iostream>
#include<vector>

using namespace std;
int dcurve[101][101];
vector<int> dir;
int ans;
int main()
{
    ans = 0;
    int n;
    cin>>n;
    int i,j,k;
    int x,y,d,g;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            dcurve[i][j] = 0;
        }
    }
    for(i=0;i<n;i++)
    {
        cin>>x>>y>>d>>g;
        dir.push_back(d);
        dcurve[y][x] = 1;
        for(j=1;j<=g;j++)
        {
            int size = dir.size();
            for(k=size-1;k>=0;k--){
                dir.push_back((dir[k]+1)%4);
            }
        }
        for(j=0;j<dir.size();j++)
        {
            if(dir[j] == 0) x++;
            else if(dir[j] == 1) y--;
            else if(dir[j] == 2) x--;
            else if(dir[j] == 3) y++;
            dcurve[y][x] = 1;
        }
        dir.clear();
    }
    for(i=0;i<=100;i++)
    {
        for(j=0;j<=100;j++)
        {
            if(dcurve[i][j] == 1 && dcurve[i+1][j] == 1 && dcurve[i][j+1]== 1 && dcurve[i+1][j+1] == 1) ans++;
        }
    }
    cout<<ans<<endl;
}
