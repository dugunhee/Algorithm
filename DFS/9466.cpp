#include<iostream>
#include<algorithm>
using namespace std;

int N;
int cnt;
int student[100001];
int visited[100001];
int finished[100001];
void dfs(int curr)
{
    visited[curr] = 1;
    int next = student[curr];
    if(visited[next])
    {
        if(!finished[next])
        {
            //if(next == curr) cnt++;
            for(int i=next;i!=curr;i=student[i]) cnt++;
            cnt++;
        }
    }
    else dfs(next);
    finished[curr] = 1;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin >> N;
        cnt = 0;
        for(int i=0;i<N;i++)
        {
            cin >> student[i];
            student[i]--;
        }
        fill(visited, visited+N, 0);
        fill(finished, finished+N, 0);
        for(int i=0;i<N;i++)
        {
            if(!visited[i]) dfs(i);
        }
        cout<<N-cnt<<endl;
    }
}