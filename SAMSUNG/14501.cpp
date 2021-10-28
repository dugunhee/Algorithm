#include<iostream>
#include<algorithm>
using namespace std;
int t[21];
int p[21];
int dp[21]= {0,};
int main()
{
    int N;
    cin>>N;
    int i;
    for(i=1;i<=N;i++)
    {
        cin>>t[i]>>p[i];
    }   
    dp[0] = dp[1] = 0;
    for(i=1;i<=N+1;i++)
    {
        int tmp=0;
        for(int j=1;j<=i;j++)
        {
            tmp = max(tmp,dp[j]);
        }
        dp[i] = tmp;
        dp[i+t[i]] = max(dp[i+t[i]],dp[i] + p[i]);
    }
    int ans = -1;
    for(i=1;i<=N+1;i++)
    {
        ans = max(dp[i],ans);
    }
    cout<<ans<<endl;
}