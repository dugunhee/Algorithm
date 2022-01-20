#include <string>
#include <vector>
#include <set>
#include<utility>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
set<string> s;
vector<string> vec;
int eflag = 0;
bool solution(vector<string> phone_book) {
    bool answer = true;
    int minlen = 21;
    sort(phone_book.begin(),phone_book.end());
    for(int i=0;i<phone_book.size();i++)
    {
        int len = phone_book[i].length();
        minlen = min(minlen, len);
        for(int j=minlen;j<=len;j++)
        {
            string tmp = phone_book[i].substr(0,j);
            if(s.find(tmp) != s.end()) eflag = 1;
        }
        if(eflag == 1) {
            answer = false;
            break;
        }
        s.insert(phone_book[i]);
    }
    
    return answer;
}