#include<iostream>
using namespace std;
long long dp[10][1000];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<10;i++)
    {
        dp[i][1] = 1;
    }
    for(int i=2;i<n+1;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=j;k<10;k++)
            {
                dp[j][i] += dp[k][i-1];
                dp[j][i] %= 10007;
            }
        }
    }
    long long ans = 0;
    for(int i=0;i<10;i++){
        ans+= dp[i][n];
        ans%=10007;
    }
    cout<<ans<<endl;
}