#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
//#include <functional>
using namespace std;
priority_queue<int,vector<int>,greater<int>> pq;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    while(1){
        if(pq.top() >= K)break;
        else{
            if(pq.size() <= 1){
                answer = -1;
                break;
            }
        }
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a+2*b);
        answer++;
    }
    return answer;
}