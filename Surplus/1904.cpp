#include<iostream>

using namespace std;
int sticker[1000001];
int main()
{
    int n;
    cin>>n;
    sticker[1] = 1;
    sticker[2] = 2;
    sticker[3] = 3;
    sticker[4] = 5;
    for(int i=5;i<n+1;i++)
    {
        sticker[i] = (sticker[i-2] + sticker[i-1])%15746;
    }
    cout<<sticker[n]<<endl;
}