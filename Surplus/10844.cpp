#include<iostream>
#include<string>
#include<vector>
using namespace std;
long long dp[10][100];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<10;i++)
    {
        dp[i][1] = 1;
    }
    for(int j=2;j<n+1;j++)
    {
        for(int i=0;i<10;i++)
        {
            if(i==0){
                dp[i][j] = dp[i+1][j-1]%1000000000;
            }
            else if(i>=1&&i<9){
                dp[i][j] = (dp[i+1][j-1]%1000000000 + dp[i-1][j-1]%1000000000)%1000000000;
            }
            else if(i==9){
                dp[i][j] = dp[i-1][j-1]%1000000000;
            }
        }
    }
    long long ans=0;
    for(int i=1;i<10;i++)
    {
        ans += dp[i][n]%1000000000;
        ans %= 1000000000;
    }
    cout<<ans<<endl;
}