#include<iostream>
#include<algorithm>
using namespace std;
int num[350];
int dp[100000];
int main()
{
    for(int i=0;i<350;i++)
    {
        num[i] = i*i;
    }
    int n;
    cin>>n;
    for(int i=0;i<n+1;i++)
    {
        dp[i] = 0;
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<350;j++)
        {
            if(i<num[j]){
                break;
            }
            if(dp[i] == 0){
                dp[i] = dp[i-num[j]]+1;
            }
            else{
                dp[i] = min(dp[i],dp[i-num[j]]+1);
            }
        }
    }
    cout<<dp[n]<<endl;
}