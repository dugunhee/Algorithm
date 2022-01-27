#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
set<int> s;
int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(),numbers.end());
    do{
        for(int i=0;i<numbers.size();i++){
            int num = stoi(numbers.substr(0,i+1));
            int tmp = num;
            int flag = 0;
            if(num == 0 || num == 1)continue;
            for(int j=2;j<= (int)sqrt(num);j++){
                if(tmp%j == 0) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) s.insert(num);
        }
    }while(next_permutation(numbers.begin(),numbers.end()));
    answer = s.size();
    return answer;
}