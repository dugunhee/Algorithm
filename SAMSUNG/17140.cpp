#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int arr[101][101];
int r,c,k;
int row,col;
vector<pair<int,int> > vec[101];
vector<int> tmpvec;
void R()
{
    int i,j;
    for(i=1;i<=row;i++)
    {
        int tmp;
        int cnt;
        for(j=1;j<=col;j++)
        {
            tmpvec.push_back(arr[i][j]);
        }
        sort(tmpvec.begin(),tmpvec.end());
        int tmpj;
        for(j=0;j<col;j++)
        {
            if(tmpvec[j]!=0){
                tmp = tmpvec[j];
                cnt = 1;
                tmpj=j;
                break;
            }
        }
        for(j=tmpj+1;j<=col;j++)
        {
            if(tmp!=tmpvec[j] || j == col){
                vec[i].push_back(make_pair(cnt,tmp));
                tmp = tmpvec[j];
                cnt = 1;
                continue;
            }
            cnt++;
        }
        tmpvec.clear();
    }
    int mc = col;
    for(i=1;i<=col;i++)
    {
        for(j=1;j<=row;j++)arr[j][i] = 0;
    }
    for(i=1;i<=row;i++)
    {
        //for(j=1;j<=col;j++)arr[i][j] = 0;
        sort(vec[i].begin(),vec[i].end());
        int size = vec[i].size();
        for(j=0;j<vec[i].size();j++)
        {
            mc = max(mc,size*2);
            arr[i][2*j+1] = vec[i][j].second;
            arr[i][2*j+2] = vec[i][j].first;
        }
        vec[i].clear();
    }
    col = mc;
}
void C()
{
    int i,j;
    for(i=1;i<=col;i++)
    {
        int tmp;
        int cnt;
        for(j=1;j<=row;j++)
        {
            tmpvec.push_back(arr[j][i]);
        }
        sort(tmpvec.begin(),tmpvec.end());
        int tmpj;
        for(j=0;j<row;j++)
        {
            if(tmpvec[j]!=0){
                tmp = tmpvec[j];
                cnt = 1;
                tmpj=j;
                break;
            }
        }
        for(j=tmpj+1;j<=row;j++)
        {
            if(tmp!=tmpvec[j] || j == row){
                vec[i].push_back(make_pair(cnt,tmp));
                tmp = tmpvec[j];
                cnt = 1;
                continue;
            }
            cnt++;
        }
        tmpvec.clear();
    }
    int mr = row;
    for(i=1;i<=col;i++)
    {
        for(j=1;j<=row;j++)arr[j][i] = 0;
    }
    for(i=1;i<=col;i++)
    {
        sort(vec[i].begin(),vec[i].end());
        int size = vec[i].size();
        for(j=0;j<vec[i].size();j++)
        {
            mr = max(mr,size*2);
            arr[2*j+1][i] = vec[i][j].second;
            arr[2*j+2][i] = vec[i][j].first;
        }
        vec[i].clear();
    }
    row = mr;
}
int main()
{
    cin>>r>>c>>k;
    int i,j;
    for(i=1;i<=100;i++)
    {
        for(j=1;j<=100;j++) arr[i][j] = 0;
    }
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++) cin>>arr[i][j];
    }
    row = 3;
    col = 3;
 
    for(i=0;i<=100;i++)
    {
        if(arr[r][c] == k){
            cout<<i<<endl;
            break;
        }
        if(row >= col) R();
        else if(row<col) C();
    }
    if(i==101)cout<<-1<<endl;
}