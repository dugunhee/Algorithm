#include<iostream>
#include<algorithm>
using namespace std;
int N,M;
int board[1000][1000];
int ans;
int glotet[4][4];
int tet1[4][4] = {
    {1,1,1,1},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
};
int tet2[4][4] = {
    {1,1,0,0},
    {1,1,0,0},
    {0,0,0,0},
    {0,0,0,0}
};
int tet3[4][4]={
    {1,0,0,0},
    {1,0,0,0},
    {1,1,0,0},
    {0,0,0,0}
};
int tet4[4][4] = {
    {1,0,0,0},
    {1,1,0,0},
    {0,1,0,0},
    {0,0,0,0}
};
int tet5[4][4] = {
    {1,1,1,0},
    {0,1,0,0},
    {0,0,0,0},
    {0,0,0,0}
};
int tet6[4][4] = {
    {0,1,0,0},
    {1,1,0,0},
    {1,0,0,0},
    {0,0,0,0}
};
int tet7[4][4] = {
    {0,1,0,0},
    {0,1,0,0},
    {1,1,0,0},
    {0,0,0,0}
};
void cal()
{
    int i,j,k,l;
    int tmp;
    for(i=0;i<N+3;i++)
    {
        for(j=0;j<M+3;j++)
        {
            tmp = 0;
            for(k=0;k<4;k++)
            {
                for(l=0;l<4;l++)
                {
                    if(glotet[k][l] == 1){
                        tmp += board[i+k][j+l];
                    }
                }
            }
            ans = max(tmp, ans);
        }
    }
}
void copy(int arr[4][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            glotet[i][j] = arr[i][j];
        }
    }
}
void rotate(){
    int tmp[4][4];
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            tmp[i][j] = glotet[i][j];
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            glotet[i][j] = tmp[j][4-i-1];
        }
    }
}
int main()
{
    cin>>N>>M;
    int i,j,k,l;
    for(i=0;i<N+7;i++)
    {
        for(j=0;j<M+7;j++)
        {
            board[i][j] = 0;
        }
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            cin>>board[i+3][j+3];
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            glotet[i][j] = tet1[i][j];
        }
    } 
    copy(tet1);
    for(i=0;i<4;i++)
    {
        cal();
        rotate();
    }
    copy(tet2);
    for(i=0;i<4;i++)
    {
        cal();
        rotate();
    }
    copy(tet3);
    for(i=0;i<4;i++)
    {
        cal();
        rotate();
    }
    copy(tet4);
    for(i=0;i<4;i++)
    {
        cal();
        rotate();
    }
    copy(tet5);
    for(i=0;i<4;i++)
    {
        cal();
        rotate();
    }
    copy(tet6);
    for(i=0;i<4;i++)
    {
        cal();
        rotate();
    }
    copy(tet7);
    for(i=0;i<4;i++)
    {
        cal();
        rotate();
    }
    cout<<ans<<endl;
}
