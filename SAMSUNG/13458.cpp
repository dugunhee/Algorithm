#include<iostream>

using namespace std;
int N;
long long int arr[1000001];
int B,C;
int main()
{
    long long int cnt=0;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>> arr[i];
    }
    cin>>B>>C;
    for(int i=0;i<N;i++)
    {
        arr[i]-=B;
        cnt++;
        if(arr[i] < 0)arr[i] = 0;
    }
    for(int i=0;i<N;i++)
    {
        if(arr[i]%C == 0)
        {
            cnt+= (arr[i]/C);
        }
        else cnt+= (arr[i]/C + 1);
    }
    cout<<cnt<<endl;
}