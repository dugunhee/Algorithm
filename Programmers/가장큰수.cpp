#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
vector<int> arr[10];

bool cmp(string a, string b){
    return a+b>b+a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> tmp;
    for(int i=0;i<numbers.size();i++)
    {
        tmp.push_back(to_string(numbers[i]));
    }
    sort(tmp.begin(),tmp.end(),cmp);
    for(int j=0;j<tmp.size();j++)
    {
        answer+=tmp[j];
    }
    if(answer[0] == '0') answer = "0";
    cout<<endl;
    return answer;
}