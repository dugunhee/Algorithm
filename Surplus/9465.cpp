#include<iostream>
#include<algorithm>
using namespace std;
int arr[2][100001];
int sticker[2][100001];
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        for(int j=0;j<2;j++){
            for(int k=0;k<n;k++){
                cin>>arr[j][k];
            }
        }
        sticker[0][0] = arr[0][0];
        sticker[1][0] = arr[1][0];
        sticker[0][1] = arr[0][1] + arr[1][0];
        sticker[1][1] = arr[1][1] + arr[0][0];
        for(int j=2;j<n;j++)
        {
            sticker[0][j] = arr[0][j] + max(sticker[1][j-1],sticker[1][j-2]);
            sticker[1][j] = arr[1][j] + max(sticker[0][j-1],sticker[0][j-2]);
        }
        cout<<max(sticker[0][n-1],sticker[1][n-1])<<endl;
    }
}