#include<iostream>

using namespace std;

int n = 10;
int arr[] = {1, 10, 5,8,7,6,4,3,2,9};
void quicksort(int* arr, int left, int right){
    if(left>=right) return;
    int pivot = left;
    int i = left+1;
    int j = right;
    int temp = 0;
    while(i<=j){
        while(i<=right && arr[i]<=arr[pivot]){
            i++;
        }
        while(j>left && arr[j]>=arr[pivot]){
            j--;
        }
        if(i>j){
            temp = arr[pivot];
            arr[pivot] = arr[j];
            arr[j] = temp;
        }else{
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    quicksort(arr,left, j-1);
    quicksort(arr,j+1,right);
}
int main()
{
    quicksort(arr,0,9);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
}