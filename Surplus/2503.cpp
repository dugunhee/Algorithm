#include<iostream>

using namespace std;
int arr[1000];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<999;i++)
    {
        arr[i] = 1;
    }
    int num,s,b;
    int tmp;
    int scnt=0;
    int bcnt=0;
    int x,y,z;
    int xx,yy,zz;
    for(int i=0;i<n;i++)
    {
        cin>>num>>s>>b;
        tmp = 0;
        xx = (num/10)/10;
        yy = (num/10)%10;
        zz = (num%10);
        for(int j=123;j<999;j++)
        {
            tmp = j;
            scnt=0;
            bcnt=0;
            x = (tmp/10)/10;
            y = (tmp/10)%10;
            z = (tmp%10);
            if(x==y || y==z || x == z || x==0 || y==0||z==0) {
                arr[j]=0;
                continue;
            }
            if(x==xx)scnt++;
            if(y==yy)scnt++;
            if(z==zz)scnt++;
            if(x == yy || x == zz)bcnt++;
            if(y == xx || y == zz)bcnt++;
            if(z == xx || z == yy)bcnt++;
            if(arr[j] == 1 && scnt == s && bcnt == b) arr[j] = 1;
            else{
                arr[j] = 0;
            }
        }
    }
        int cnt=0;
        for(int i=123;i<999;i++)
        {
            if(arr[i] == 1) cnt++;
        }
        cout<<cnt<<endl;
}