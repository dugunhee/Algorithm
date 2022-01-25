#include <string>
#include <vector>
#include <stack>
using namespace std;
stack<int> st;
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for (int i = 0; i < prices.size(); i++) {
        int price = 0;
        for (int j = i + 1; j < prices.size(); j++) {
            if (prices[j] >= prices[i]) price++;
            else {
                price++;
                break;
            }
        }
        answer.push_back(price);
    }
    return answer;
}