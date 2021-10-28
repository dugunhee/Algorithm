#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int area[21][21];
int visit[21][21];
vector<int> sum(5);
int ans=987654321;
int N;
int main()
{
    int x,y,d1,d2;
    int i,j,k,l;
    cin>>N;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            cin>>area[i][j];
        }
    }
    
    int r=0,c=0;
    for(x=1;x<=N;x++)
    {
        for(y=1;y<=N;y++)
        {
            for(d1=1;d1<=N;d1++)
            {
                for(d2=1;d2<=N;d2++)
                { 
                    for(i=0;i<5;i++)
                    {
                        sum[i] = 0;
                    }
                    if(1 <= x&& x < (x+d1+d2) && (x+d1+d2) <= N && 1 <= (y-d1) && (y-d1) < y && y < (y+d2) && (y+d2) <= N)
                    {  
                    for(r=1;r<=N;r++)
                    {
                        for(c=1;c<=N;c++)
                        {
                            if(((r+c)>=(x+y)) &&((r+c)<=(x+y+2*d2)) && (((r-c)<=(x-y+2*d1))&&((r-c)>=(x-y))))
                            {
                                visit[r][c] = 5;
                            }
                            else{
                                if(1<=r&&r<(x+d1) && 1<=c&&c<=y)
                                {
                                    //sum[0] += area[r][c];
                                    visit[r][c] = 1;
                                }
                                else if(1<=r&&r<=(x+d2) && y<c&&c<=N)
                                {
                                    //sum[1] += area[r][c];
                                    visit[r][c] = 2;
                                }
                                else if((x+d1)<=r&&r<=N && 1<=c&&c<(y-d1+d2))
                                {
                                    //sum[2] += area[r][c];
                                    visit[r][c] = 3;
                                }
                                else if((x+d2)<r&&r<=N && (y-d1+d2)<=c&&c<=N)
                                {   
                                    //sum[3] += area[r][c];
                                    visit[r][c] = 4;
                                }
                            }    
                        }
                    }
                    for(r=1;r<=N;r++)
                    {
                        for(c=1;c<=N;c++)
                        {
                            sum[visit[r][c]-1] += area[r][c];
                        }
                    }
                    sort(sum.begin(),sum.end());
                    if(ans>(sum[4]-sum[0]))
                    {
                        ans = sum[4]-sum[0];
                    }
                    }
                    else continue;
               }
            }
        }
    }
    cout<<ans<<endl;
}