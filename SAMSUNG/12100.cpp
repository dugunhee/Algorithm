#include<iostream>
#include<algorithm>
using namespace std;
int n;
int arr[20][20];
int change[20][20];
int cnt;
int ans = -1;
void move(int op)
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++) change[i][j] = 0;
    }
    if(op == 1)//left
    {
        for(i=0;i<n;i++)
        {
            for(j=1;j<n;j++)
            {
                int x = i;
                int y = j;
                for(k=1;k<n;k++)
                {
                    if(j>=k){
                    if(change[x][y] == 0 && change[x][y-1] == 0 && arr[x][y] != 0 && arr[x][y] == arr[x][y-1]){
                        arr[x][y-1] += arr[x][y];
                        arr[x][y] = 0;
                        change[x][y-1] = 1;
                        change[x][y] = 0;
                    }
                    else if(arr[x][y-1] == 0) {
                        arr[x][y-1] = arr[x][y];
                        arr[x][y] = 0;
                        change[x][y-1] = change[x][y];
                        change[x][y] = 0;
                    }
                    y--;
                    }
                }
            }
        }
    }
    else if(op==2)//right
    {
        for(i=0;i<n;i++)
        {
            for(j=n-1;j>=0;j--)
            {
                int x = i;
                int y = j;
                for(k=1;k<n;k++)
                {
                    if(j<n-k){
                    if(change[x][y] == 0 &&change[x][y+1] == 0 && arr[x][y] != 0 && arr[x][y] == arr[x][y+1]){
                        arr[x][y+1] += arr[x][y];
                        arr[x][y] = 0;
                        change[x][y+1] = 1;
                        change[x][y] = 0;
                    }
                    else if(arr[x][y+1] == 0) {
                        arr[x][y+1] = arr[x][y];
                        arr[x][y] = 0;
                        change[x][y+1] = change[x][y];
                        change[x][y] = 0;
                    }
                    y++;
                    }
                }
            }
        }
    }
    else if(op==3)//up
    {
        for(i=0;i<n;i++)
        {
            for(j=1;j<n;j++)
            {
                int x = i;
                int y = j;
                for(k=1;k<n;k++)
                {
                    if(j>=k){
                    if(change[y][x] == 0 &&change[y-1][x] == 0 && arr[y][x] != 0 && arr[y][x] == arr[y-1][x]){
                        arr[y-1][x] += arr[y][x];
                        arr[y][x] = 0;
                        change[y-1][x] = 1;
                        change[y][x] = 0;
                    }
                    else if(arr[y-1][x] == 0) {
                        arr[y-1][x] = arr[y][x];
                        arr[y][x] = 0;
                        change[y-1][x] = change[y][x];
                        change[y][x] = 0;
                    }
                    y--;
                    }
                }
            }
        }
    }
    else if(op==4)//down
    {
        for(i=0;i<n;i++)
        {
            for(j=n-1;j>=0;j--)
            {
                int x = i;
                int y = j;
                for(k=1;k<n;k++)
                {
                    if(j<n-k){
                    if(change[y][x] == 0 && change[y+1][x] == 0 && arr[y][x] != 0 && arr[y][x] == arr[y+1][x]){
                        arr[y+1][x] += arr[y][x];
                        arr[y][x] = 0;
                        change[y+1][x] = 1;
                        change[y][x] = 0;
                    }
                    else if(arr[y+1][x] == 0) {
                        arr[y+1][x] = arr[y][x];
                        arr[y][x] = 0;
                        change[y+1][x] = change[y][x];
                        change[y][x] = 0;
                    }
                    y++;
                    }
                }
            }
        }
    }
    /*
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            ans = max(ans,arr[i][j]);
            //map[i][j] = arr[i][j];
        }
    }*/
}
void dfs(int cm)
{
    int tmp[20][20];
    
    if(cm==5){
        for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans = max(ans, arr[i][j]);
            //map[i][j] = arr[i][j];
        }
    }
        return;
    } 
    //cnt++;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            tmp[i][j] = arr[i][j];
        }
    }
    for(int k=1;k<=4;k++)
    {
        move(k);
        //move(arr, k);
        dfs(cm+1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr[i][j] = tmp[i][j];
            }
        }
    }
    
}
int main()
{
    cnt = 0;
    cin>>n;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    dfs(0);
    cout<<ans<<endl;
}