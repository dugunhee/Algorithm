#include<iostream>
#include<algorithm>
using namespace std;

int arr[1000001];

int main()
{
    int x;
    cin>>x;
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    int tmp;
    if(x >3){
        for(int i = 4;i<=x;i++)
        {
            tmp = arr[i-1];
            if(i%3 == 0)
            {
                tmp = min(tmp,arr[i/3]);
            }
            if(i%2 == 0)
            {
                tmp = min(tmp,arr[i/2]);
            }
            arr[i] = tmp+1;
        }
    }
    cout<<arr[x]<<endl;
}