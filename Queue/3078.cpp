#include<iostream>
#include<queue>
#include<string>
using namespace std;
queue<int> q[21];
int main()
{
    long long cnt=0;
    int n,k;
    cin>>n>>k;
    string name;
    int len;
    for(int i=0;i<n;i++){
        cin>>name;
        len = name.length();
        while(!q[len].empty() && i-q[len].front() > k){
            q[len].pop();
        }
        cnt+=q[len].size();
        q[len].push(i);
    }
    cout<<cnt;
}