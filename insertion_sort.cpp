#include<iostream>

using namespace std;

int arr[5] = {3,2,4,1,5};

int main()
{
    int i,j,temp;
    int prev;
    for(i=1;i<5;i++)
    {
        temp = arr[i];
        prev = i-1;
        while((prev>=0) && (arr[prev] > temp)){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = temp;
    }
    for(i=0;i<5;i++)
    {
        cout<<arr[i]<<' ';
    }
}