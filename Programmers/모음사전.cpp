#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> vec;
char moeum[5] = {'A','E','I','O','U'};
bool cmp(string a, string b){
    return a<b;
}
void makeword(string str,int cnt)
{
    if(cnt >= 5) return;
    string tmp = str;
    for(int i=0;i<5;i++)
    {
        str+=moeum[i];
        vec.push_back(str);
        makeword(str,++cnt);
        str = tmp;
        cnt--;
    }
}
int solution(string word) {
    int answer = 0;
    makeword("",0);
    sort(vec.begin(),vec.end(),cmp);
    for(int i=0;i<vec.size();i++)
    {
        if(!vec[i].compare(word)){
            answer = i+1;
            break;
        }
    }
    return answer;
}