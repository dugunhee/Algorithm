#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef struct st{
    int x;
    int pr;
}st;
struct compare{
    bool operator()(st f, st s) {
        //if(f.pr != s.pr) return f.pr<s.pr;
        //return f.x>s.x;
        return f.pr<s.pr;
    }
};
queue<st> q;
priority_queue<st, vector<st>, compare> pq;
int main()
{
    int T;
    cin>>T;
    st prior;
    while(T--){
        int n,m;
        int mpr;
        int cnt=0;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            prior.x = i;
            cin>>prior.pr;
            if(i==m)mpr = prior.pr;
            //cout<<"xxxxx:C"<<mpr<<endl;
            q.push(prior);
            pq.push(prior);
        }
        while(!q.empty()){
            if(pq.top().pr != q.front().pr){
                q.push(q.front());
                q.pop();
                continue;
            }
            else{
                cnt++;
                if(q.front().x == m){
                    cout<<cnt<<endl;
                    while(!q.empty())q.pop();
                    while(!pq.empty())pq.pop();
                    break;
                }
                q.pop();
                pq.pop();
            }
        }
    }
}