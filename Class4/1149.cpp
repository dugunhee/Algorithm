#include<iostream>
#include<algorithm>
using namespace std;
int color[1001][3];
int dp[1001][3];
int N;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            cin>>color[i][j];
        }
    }
    for(int i=0;i<3;i++){
        dp[0][i] = color[0][i];
    }
    for(int i=1;i<N;i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + color[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + color[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + color[i][2];
    }   
    int ans = min(dp[N-1][0],dp[N-1][1]);
    ans = min(ans, dp[N-1][2]);
    cout<<ans<<endl;
}