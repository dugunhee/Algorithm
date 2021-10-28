#include<iostream>
#include<algorithm>
using namespace std;
int price[1000];
int dp[1000];
int main()
{
    int n;
    cin>>n;
    price[0] = 0;
    for(int i=1;i<n+1;i++){
        cin>>price[i];
    }
    dp[0] = 0;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++){
            if(i<j) break;
            dp[i] = max(dp[i],dp[i-j]+price[j]);
        }
    }
    cout<<dp[n]<<endl;
}