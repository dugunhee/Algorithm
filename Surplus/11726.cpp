#include<iostream>

using namespace std;
int arr[1000];
int main()
{
    int n;
    cin>>n;
    arr[1] = 1;
    arr[2] = 3;
    arr[3] = 5;
    for(int i=4;i<n+1;i++)
    {
        arr[i] = (arr[i-1] + arr[i-2]*2)%10007;
    }
    cout<<arr[n]<<endl;
}