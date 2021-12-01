#include<iostream>

using namespace std;

int n = 10;
int arr[] = {1,10,5,8,7,6,4,3,2,9};
int sorted[10];
void merge(int* arr, int left, int mid, int right){
    int i = left;
    int j = mid+1;
    int k = left;
    while(i<=mid && j<=right){
        if(arr[i] < arr[j]){
            sorted[k] = arr[i];
            i++;
        }else{
            sorted[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=right){
            sorted[k] = arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            sorted[k] = arr[i];
            i++;
            k++;
        }
    }
    for(i=left;i<=right;i++)
    {
        arr[i] = sorted[i];
    }
}
void mergesort(int* arr, int left, int right){
    if(left<right){
        int mid = (left+right)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
int main()
{
    mergesort(arr,0,9);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
}