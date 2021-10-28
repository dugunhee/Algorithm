#include<iostream>
#include<algorithm>
using namespace std;
int coin[101];
int dp[10001];
int main()
{
    int n;
    int total;
    cin>>n>>total;
    for(int i=0;i<n;i++)
    {
        cin>>coin[i];
    }
    dp[0] = 0;
    sort(&coin[0],&coin[n-1]);
    for(int i=1;i<=total;i++) dp[i] = -1;
    for(int i=1;i<=total;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j!=0 && coin[j] == coin[j-1])continue;
            if(i-coin[j] >= 0){
                if(dp[i-coin[j]]==-1){ continue;}
                if(dp[i] != -1)dp[i] = min(dp[i],dp[i-coin[j]] + 1);
                else dp[i] = dp[i-coin[j]] +1;
            }
        }
    }
    cout<<dp[total]<<endl;
}
