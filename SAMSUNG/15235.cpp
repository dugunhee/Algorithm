#include<iostream>
#include<queue>
#include<utility>
using namespace std;
queue<pair<int,int> > q;
int main()
{
    int N;
    int pizza;
    int ans[1001];
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>pizza;
        q.push(make_pair(i,pizza));
    }
    int cnt=1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        y--;
        if(y == 0)ans[x] = cnt;
        else{
            q.push(make_pair(x,y));
        }
        cnt++;
    }
    for(int i=0;i<N;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}