#include<iostream>
//#include<algorithm>
using namespace std;
int arr[11] = {0,10,9,8,7,6,5,4,3,2,1};
    int arr1[11];
    int arr2[11];
void max_sum(int n, //입력 배열의 크기
int s[], // 입력 배열
int s1[], int s2[]) //2개의 분할된 출력 배열
{
    int i,j;
    int low=1, high=10;
    int pivotpoint=1;
    do {
        int pitem = arr[low];
        j = low;
        for(i=low+1;i<=high;i++){
            if(arr[i]<pitem){
                //cout<<arr[i]<<endl;
                j++;
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        //for(i=1;i<=10;i++)cout<<arr[i]<<' ';
        //cout<<endl;
        pivotpoint = j;
        int tmp = arr[low];
        arr[low] = arr[pivotpoint];
        arr[pivotpoint] = tmp;
        cout<<"low: "<<low<<"high : "<<high<<endl;
    } while (pivotpoint!=5);
    for(int i=1;i<=5;i++){
        arr1[i] = arr[i];
        arr2[i] = arr[n/2+i];
    }
}

int main()
{
    max_sum(10,arr,arr1,arr2);
    cout<<"arr1"<<endl;
    for(int i=1;i<=5;i++){
        cout<<arr1[i]<<' ';
    }
    cout<<endl;
    cout<<"arr2"<<endl;
    for(int i=1;i<=5;i++){
        cout<<arr2[i]<<' ';
    }
    cout<<endl;
}
