#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
stack<int> st;
vector<int> ans;
int cnt =0;
string solution(int n, int t, int m, int p) {
    string answer = "";
    int num = 0;
    for(int i=0;;i++)
    {
        if(t==0)break;
        if(i == 0){
            if(cnt%m == p-1){
                t--;
                ans.push_back(0);
            }
            cnt++;
            continue;
        }
        num = i;
        while(num != 0){
            st.push(num%n);
            num /= n;
        }
        while(!st.empty()){
            if(t>0 && cnt%m == p-1){
                t--;
                ans.push_back(st.top());
            }
            st.pop();
            cnt++;
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]>=10){
            answer += (ans[i]-10 + 'A');
            continue;
        }
        answer+= to_string(ans[i]);
    }
    return answer;
}