#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int ans[3];
int one[5] = {1,2,3,4,5};
int two[8] = {2,1,2,3,2,4,2,5};
int three[10] = {3,3,1,1,2,2,4,4,5,5};
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    for(int i=0;i<3;i++){
        int k=0;
        int tmp = 0;
        for(int j=0;j<answers.size();j++){
            if(i == 0 && answers[j] == one[k%5])tmp++;
            else if(i == 1 && answers[j] == two[k%8])tmp++;
            else if(i == 2 && answers[j] == three[k%10])tmp++;
            k++;
        }
        ans[i] = tmp;
    }
    int a;
    a = max(max(ans[0],ans[1]),ans[2]);
    for(int i=0;i<3;i++){
        if(a == ans[i]) answer.push_back(i+1);
    }
    return answer;
}