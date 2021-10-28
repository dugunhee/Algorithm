    #include<iostream>

    using namespace std;
    char candy[51][51];
    int ans;
    int N;
    void findcandy()
    {
        int len=0;
        for(int i=0;i<N;i++)
        {
            len = 1;
            for(int j=1;j<N;j++)
            {
                if(candy[i][j] == candy[i][j-1]) {
                    len++;
                    if(ans < len) ans = len;
                }
                else len = 1;
            }
        }
        for(int i=0;i<N;i++)
        {
            len = 1;
            for(int j=1;j<N;j++)
            {
                if(candy[j][i] == candy[j-1][i]) {
                    len++;
                    if(ans < len) ans = len;
                }
                else len =1;
            }
            if(ans < len) ans = len;
        }
    }
    int main()
    {
        cin>>N;
        int i,j,k;
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                cin>>candy[i][j];
            }
        }
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                for(k=0;k<2;k++)
                {
                    if(k == 0)
                    {
                        if(candy[i][j] == candy[i][j+1] || j+1 >= N) continue;
                        int tmp;
                        tmp = candy[i][j+1];
                        candy[i][j+1] = candy[i][j];
                        candy[i][j] = tmp;
                        findcandy();
                        tmp = candy[i][j+1];
                        candy[i][j+1] = candy[i][j];
                        candy[i][j] = tmp;
                    }
                    else{
                        if(candy[i][j] == candy[i+1][j] || i+1 >= N) continue;
                        int tmp;
                        tmp = candy[i+1][j];
                        candy[i+1][j] = candy[i][j];
                        candy[i][j] = tmp;
                        findcandy();
                        tmp = candy[i+1][j];
                        candy[i+1][j] = candy[i][j];
                        candy[i][j] = tmp;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
