#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
int stat[20][20];
int num[20];
vector<int> vec1;
vector<int> vec2;
int main()
{
    cin>>N;
    int i,j;
    //int total = 0;
    for(i=0;i<N;i++)num[i] = 0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            cin>>stat[i][j];
        }
    }
    for(i=0;i<N/2;i++)num[i] = 1;
    int tmp = 987654321;
    sort(num,num+N);
    do{
        int tmp1=0;
        int tmp2=0;
        vec1.clear();
        vec2.clear();
        for(i=0;i<N;i++)
        {
            if(num[i] == 1) vec1.push_back(i);
            else if(num[i] == 0)vec2.push_back(i);
        }
        for(i=0;i<N/2;i++){
            for(j=0;j<N/2;j++){
                tmp1+= stat[vec1[i]][vec1[j]];
            }
        }
        for(i=0;i<N/2;i++){
            for(j=0;j<N/2;j++){
                tmp2+= stat[vec2[i]][vec2[j]];
            }
        }
        tmp = min(tmp, abs(tmp1-tmp2));
    }while(next_permutation(num,num+N-1));
    cout<<tmp<<endl;
}