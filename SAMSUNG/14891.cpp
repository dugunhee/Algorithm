#include<iostream>

using namespace std;
int arr1[10];
int arr2[10];
int arr3[10];
int arr4[10];
int f1,f2,f3,f4,e1,e2,e3,e4;
int visit[5];
void rotate(int num, int dir)
{
    int tmp;
    visit[num] = 1;
    if(dir == -1)
    {
        if(num == 1) tmp = arr1[0];
        else if(num == 2) tmp = arr2[0];
        else if(num == 3) tmp = arr3[0];
        else if(num == 4) tmp = arr4[0];
        for(int i=0;i<=7;i++)
        {
            if(num == 1){ 
                if(i == 7) arr1[i] = tmp;
                else arr1[i] = arr1[i+1]; 
            }
            else if(num == 2){
                if(i == 7) arr2[i] = tmp;
                else arr2[i] = arr2[i+1]; 
            }
            else if(num == 3){
                if(i == 7) arr3[i] = tmp;
                else arr3[i] = arr3[i+1]; 
            }
            else if(num == 4){
                 if(i == 7) arr4[i] = tmp;
                 else arr4[i] = arr4[i+1]; 
            }
        }
    }
    else if(dir == 1){
        if(num == 1) tmp = arr1[7];
        else if(num == 2) tmp = arr2[7];
        else if(num == 3) tmp = arr3[7];
        else if(num == 4) tmp = arr4[7];
        for(int i=6;i>=-1;i--)
        {
            if(num == 1){ 
                if(i == -1) arr1[0] = tmp;
                else arr1[i+1] = arr1[i]; 
            }
            else if(num == 2){
                if(i == -1) arr2[0] = tmp;
                else arr2[i+1] = arr2[i]; 
            }
            else if(num == 3){
                if(i == -1) arr3[0] = tmp;
                else arr3[i+1] = arr3[i];
            }
            else if(num == 4){
                 if(i == -1) arr4[0] = tmp;
                 else arr4[i+1] = arr4[i];
            }
        }
    }
}
int main()
{
    int i,j;
    int ntmp;
    
    cin>>ntmp;
    
        for(j=7;j>0;j--)
        {
            arr1[j] = ntmp%10;
            ntmp/=10;
        }
    arr1[0] = ntmp;
    cin>>ntmp;
    
        for(j=7;j>0;j--)
        {
            arr2[j] = ntmp%10;
            ntmp/=10;
        }
    arr2[0] = ntmp;
    cin>>ntmp;
    
        for(j=7;j>0;j--)
        {
            arr3[j] = ntmp%10;
            ntmp/=10;
        }
    arr3[0] = ntmp;
    cin>>ntmp;
    
        for(j=7;j>0;j--)
        {
            arr4[j] = ntmp%10;
            ntmp/=10;
        }
    arr4[0] = ntmp;
    f1 = arr1[6];
    f2 = arr2[6];
    f3 = arr3[6];
    f4 = arr4[6];
    e1 = arr1[2];
    e2 = arr2[2];
    e3 = arr3[2];
    e4 = arr4[2];
    int k;
    cin>>k;
    int num, dir;
    for(i=0;i<k;i++)
    {
        cin>>num>>dir;
        for(j=1;j<5;j++)
        {
            visit[j] = 0;
        }
        rotate(num,dir);
        if(num == 1)
        {
            if(e1 != f2) rotate(2,dir*(-1));
            if(visit[2] == 1 && e2 != f3) rotate(3, dir);
            if(visit[3] == 1 && e3 != f4) rotate(4, dir*(-1));
        }
        else if(num == 2){
            if(e1 != f2) rotate(1,dir*(-1));
            if(e2 != f3) rotate(3, dir*(-1));
            if(visit[3] == 1&&e3 != f4) rotate(4, dir);
        }
        else if(num == 3){
            if(e2 != f3) rotate(2,dir*(-1));
            if(e3 != f4) rotate(4, dir*(-1));
            if(visit[2] == 1 && e1 != f2) rotate(1,dir);
        }
        else if(num == 4){
            if(e3 != f4) rotate(3,dir*(-1));
            if(visit[3] == 1 && e2 != f3) rotate(2,dir);
            if(visit[2] == 1 && e1 != f2) rotate(1,dir*(-1));
        }
        f1 = arr1[6];
        f2 = arr2[6];
        f3 = arr3[6];
        f4 = arr4[6];
        e1 = arr1[2];
        e2 = arr2[2];
        e3 = arr3[2];
        e4 = arr4[2];
        
    }
    int ans = 0;
    if(arr1[0] == 1) ans += 1;
    if(arr2[0] == 1) ans += 2;
    if(arr3[0] == 1) ans += 4;
    if(arr4[0] == 1) ans += 8;
    cout<<ans<<endl;
}