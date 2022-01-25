#include <string>
#include <vector>
#include<deque>
#include<utility>
#include<algorithm>
#include<iostream>
#include<functional>
using namespace std;
vector< pair<int, int>> vec;
vector<int> vtmp;
deque< pair<int,int>> dq;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    vtmp = priorities;
    sort(vtmp.begin(),vtmp.end(),greater<>());
    for(int i=0;i<priorities.size();i++)
    {
        dq.push_back(make_pair(priorities[i],i));
    }
    int i=0;
    while(!dq.empty())
    {
        int a = dq.front().first;
        int b = dq.front().second;
        dq.pop_front();
        if(vtmp[0] == a){
            answer++;
            vtmp.erase(vtmp.begin());
            if(b == location) break;
            continue;
        }
        dq.push_back(make_pair(a,b));
    }
    return answer;
}