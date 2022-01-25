#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
struct cmp{
    bool operator()(pair<int,int> a,pair<int,int> b){
        if(a.first != b.first) return a.first>b.first;
        else{
            if(a.second>b.second) return a.second>b.second;
        }
    }
};
priority_queue<pair<int,int>,vector<pair<int,int> >,cmp> pq;
vector<pair<int,int> > vec;
int solution(vector<vector<int> > jobs) {
    int answer = 0;
    int cnt = 0;
    sort(jobs.begin(),jobs.end());
    int i=0;
    int ans = 0;
    while(i<jobs.size() || !pq.empty()){
        if(i<jobs.size() && answer>=jobs[i][0]){
            pq.push({jobs[i][1],jobs[i][0]});
            i++;
            continue;
        }
        if(!pq.empty()){
            answer += pq.top().first;
            ans += (answer -pq.top().second);
            pq.pop();
        }
        else answer = jobs[i][0];
    }
    ans /= jobs.size();
    return ans;
}