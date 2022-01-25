#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int now_weight=0;
    int end_size = 0;
    int truck_num = truck_weights.size();
    queue< pair<int,int>> q;
    while(1){
        if(end_size == truck_num)break;
        
        answer++;
        if(!q.empty() && answer == (q.front().second+bridge_length)){
            now_weight -= q.front().first;
            q.pop();
            end_size++;
        }
        if(truck_weights.size() != 0 && (now_weight+truck_weights[0])<=weight){
            q.push(make_pair(truck_weights[0],answer));
            now_weight += truck_weights[0];
            truck_weights.erase(truck_weights.begin());
        }
    }
    return answer;
}