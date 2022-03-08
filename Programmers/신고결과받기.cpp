#include<iostream>
#include <string>
#include <vector>
#include <map>
#include<string.h>
using namespace std;
map<string, int> mp;
int visit[1001][1001];
int ban[1001];
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    memset(visit,0,sizeof(visit));
    memset(ban,0,sizeof(ban));
    for(int i=0;i<id_list.size();i++){
        mp[id_list[i]] = i;
    }
    for(int i=0;i<report.size();i++){
        string str1,str2;
        int idx = report[i].find(' ');
        str1 = report[i].substr(0,idx);
        str2 = report[i].substr(idx+1,report[i].length()-idx-1);
        int idx1 = mp[str1];
        int idx2 = mp[str2];
        if(visit[idx1][idx2] == 0){
            visit[idx1][idx2] = 1;
            ban[idx2]++;
        }
    }
    for(int i=0;i<id_list.size();i++){
        int cnt = 0;
        for(int j=0;j<id_list.size();j++){
            if(ban[j]>=k && visit[i][j] == 1) cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}