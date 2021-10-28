#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
vector< pair<int,int> > vec;
int dp[101][100001];
int w[101];
int v[101];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<101;i++)
    {
        for(int j=1;j<100001;j++)
        {
            dp[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(j>=w[i]) dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][k]<<endl;
}