#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool prime(long long n){
    if(n==1)return false;
    long long R = (long long)sqrt(n);
    bool flag = false;
    for(long long i=2;i<=R;i++){
        if(n%i == 0){
            flag = true;
            break;
        }
    }
    if(flag == false) return true;
    else return false;
}
string Jinsoo(int n,int k){
    string tmp = "";
    string ans = "";
    while(n>0){
        tmp = to_string(n%k);
        n /= k;
        tmp += ans;
        ans = tmp;
    }
    return ans;
}
int solution(int n, int k) {
    int answer = 0;
    string str = Jinsoo(n,k);
    int idx=-1;
    int flag = 0;
    string tmp = "";
    
    while(1){
        tmp = "";
        int idx2 = str.find("0",idx+1);
        if(idx2 == -1){
            tmp = str.substr(idx+1);
            flag = 1;
        }
        else {
            tmp = str.substr(idx+1,idx2-idx-1);
        }
        idx = idx2;
        if(tmp!= ""&& prime(stoll(tmp))) answer++;
        if(flag == 1)break;
    }
    return answer;
}