#include <string>
#include <vector>
#include <set>
using namespace std;
set<int> number;
int check(int num){
    if(num == 6)return 1;
    else if(num == 5) return 2;
    else if(num == 4) return 3;
    else if(num == 3) return 4;
    else if(num == 2) return 5;
    else return 6;
}
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int i,j;
    int zero_cnt=0;
    int correct_cnt=0;
    for(i=0;i<win_nums.size();i++)
    {
        number.insert(win_nums[i]);
    }
    for(i=0;i<lottos.size();i++){
        if(lottos[i] == 0){
            zero_cnt++;
            continue;
        }
        if(number.find(lottos[i])!=number.end()) correct_cnt++;
    }
    answer.push_back(check(correct_cnt+zero_cnt));
    answer.push_back(check(correct_cnt));
    return answer;
}