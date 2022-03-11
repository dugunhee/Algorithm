#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> apeach;
int ans[11]={0,};
int arrnum[11] = {0,};
int tot=0;
int m = 0;
void arrow(int k,int n){
    if(k==0){
        arrnum[k] = n;
        int ap = 0;
        int ry = 0;
        for(int i=10;i>=0;i--){
            if(apeach[i] ==0 && arrnum[i] == 0)continue;
            if(apeach[i] >= arrnum[i]) ap += i;
            else ry+=i;
        }
        int flag = 0;
        if(m <= (ry-ap)){
            if(m==(ry-ap)){
                for(int i=0;i<11;i++){
                    if(ans[i] == arrnum[i])continue;
                    if(ans[i] > arrnum[i]){
                        flag=1;
                        break;
                    }
                    else {
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag == 0){
                m = ry-ap;
                for(int i=0;i<11;i++){
                    ans[i] = arrnum[i];
                }
            }
        }        
        return;
    }
    if(n>apeach[k]){
        n-=(apeach[k]+1);
        arrnum[k] = apeach[k]+1;
        arrow(k-1,n);        
        n+=(apeach[k]+1);
        arrnum[k] = 0;
    }
    arrow(k-1,n);
}
vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    for(int i=0;i<11;i++){
        apeach.push_back(info[10-i]);
    }
    arrow(10,n);
    for(int i=10;i>=0;i--){
        answer.push_back(ans[i]);
    }
    int ap = 0;
    int ry = 0;
    for(int i=10;i>=0;i--){
            if(apeach[i] == 0 && ans[i] == 0)continue;
            if(apeach[i] >= ans[i]) ap += i;
            else ry+=i;
        }
    if(ap>=ry) {
        answer.clear();
        answer.push_back(-1);
    }
    return answer;
}