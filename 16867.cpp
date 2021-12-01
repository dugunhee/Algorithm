#include<iostream>

using namespace std;

int main()
{
    int arr[1000][1000]={0,};

    int i, j;
    int H,W,X,Y;
    cin>>H>>W>>X>>Y;
    for(i=0;i<H+X;i++){
        for(j=0;j<W+Y;j++){
            cin>>arr[i][j];
        }
    }
    for(i=X;i<H+X;i++){
        for(j=Y;j<W+Y;j++){
            if(arr[i][j]!=0) arr[i][j]-= arr[i-X][j-Y];
        }
    }
    for(i=0;i<H;i++)
    {
        for(j=0;j<W;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
}