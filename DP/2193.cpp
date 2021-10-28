#include<iostream>
using namespace std;
//0으로 끝나는 것과 1로 끝나는 배열 따로 저장
//long long int 타입 사용할 것
long long int arr0[100];
long long int arr1[100];
long long int ans[100];
int main()
{
    arr0[1] = 0;
    arr1[1] = 1;
    ans[1] = 1;
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        arr0[i] = arr0[i-1] + arr1[i-1];
        arr1[i] = arr0[i-1];
        ans[i] = arr0[i] + arr1[i];
    }
    cout<<ans[n]<<endl;
}