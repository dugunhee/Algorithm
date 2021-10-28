#include<iostream>
#include<algorithm>
#include<stack>
#include<utility>
using namespace std;
stack<pair<int,int> > st;
int arr[501][501];
int visit[501][501];
int dp[501][501];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int n;
int dfs(int f, int s)
{
    //int f,s;
    int ff,ss;
    //dp[f][s]= 1;
    if(dp[f][s]) return dp[f][s];
    dp[f][s]= 1;
    //int m=-1;
    /*
    for(int i=0;i<4;i++){
        ff = x+dx[i];
        ss = y+dy[i];
        if(ff>=0&&ff<n&&ss>=0&&ss<n&&visit[ff][ss]!=0&&arr[ff][ss]>=arr[x][y]) dp[x][y] = max(dp[x][y],dp[ff][ss]+1);
    }*/
        for(int i=0;i<4;i++){
            ff = f+dx[i];
            ss = s+dy[i];
            if(ff>=0&&ff<n&&ss>=0&&ss<n&&visit[ff][ss]==0&&arr[ff][ss]>arr[f][s]){
                //st.push(make_pair(ff,ss));
                //visit[ff][ss] = 1;
                dp[f][s] = max(dp[f][s],dfs(ff,ss)+1);
                //break;
            }
        }
        return dp[f][s];
    /*
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            visit[i][j] = 0;
        }
    }*/
}
int main()
{
    //ios::sync_with_stdio;
    cin.tie(0);
    cin>>n;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>arr[i][j];
            //dp[i][j] = 1;
            //visit[i][j] = 0;
        }
    }
    int ans=-1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            //cout<<dp[i][j]<<' ';
            ans = max(ans,dfs(i,j));
        }
        //cout<<endl;
    }
    cout<<ans<<endl;
}