#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;

int paper[10][10];
int papernum[5] = {0,0,0,0,0};
int cnt=0;
int ans;
int check_size(int x, int y, int size)
{
    if(x+size>10 || y+size>10) return 0;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(paper[x+i][y+j] == 0) return 0;
        }
    }
    return 1;
}
void attatch_paper(int x, int y, int size, int flag)
{
   for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            paper[x+i][y+j] = flag;
        }
    }
}
void recur(int x, int y, int attatch)
{
    int i,j;
    while(paper[x][y] == 0)
    {
        if(++y>=10)
        {
            if(++x>=10)
            {
                ans = min(ans,attatch);
                return;
            }
            y=0;
        }
    }
    if(ans <= attatch) return;
    //int size;
    for(int size = 5;size>0;--size)
    {
        if(x+size>10 || y+size>10 || papernum[size] == 5) continue;
        if(check_size(x,y,size) == 1)
        {
            attatch_paper(x,y,size,0);
            papernum[size]++;
            recur(x,y,attatch+1);
            attatch_paper(x,y,size,1);
            papernum[size]--;
        }
    }
}
int main()
{
    ans = 987654321;
    int i,j;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            cin>>paper[i][j];
            if(paper[i][j] == 1)
            {
                cnt++;
            }
        }
    }
    if(cnt==0){
        cout<<0<<endl;
        return 0;
    }
    else if(cnt == 100){
        cout<<4<<endl;
        return 0;
    }
    recur(0,0,0);
    if(ans == 987654321) ans = -1;
    cout<<ans<<endl;
}