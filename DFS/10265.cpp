#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> ans;
int n, k;
int x[1001];
int visited[1001];
int finished[1001];
int cnt;
void dfs(int curr)
{
    visited[curr] = 1;
    int next = x[curr];
    if(visited[next])
    {
        if(!finished[next])
        {
            for(int i=next;i!=curr;i=x[i]) cnt++;
            cnt++;
        }
    }
    else dfs(next);
    finished[curr] = 1;
}
int main()
{
    cin >>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
        x[i]--;
    }
    fill(visited,visited+n,0);
    fill(finished,finished+n,0);
    for(int i=0;i<n;i++)
    {
        cnt = 0;
        if(visited[i] == 0) {
            dfs(i);
            ans.push_back(cnt);
        }
    }
    int num = ans.size();
    int max = -1;
    for(int i=1;i<(1 << num);i++)
    {
        int sum = 0;
        for(int j=0;j<num;j++)
        {
            if(i&(1 << j))sum += ans[j];
        }
        if(sum <= k && sum > max) max = sum;
    }
    cout<<max<<endl;
}