#include<iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;
int minre = 10000000;
int maxre = 0;
vector<int> solution(vector<string> gems) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> answer;
    set<string> singlegems;
    map<string, int> m1;
    int cnt = 0, cou = 0;
    int mini = 1000000;
    for (int i = 0; i < gems.size(); i++)
    {
        singlegems.insert(gems[i]);
    }
    int size = singlegems.size();
    vector<int> arr(size,-1);
    vector<int> tmp(size,-1);
    set<string>::iterator it;
    int res = 0;
    for (it = singlegems.begin(); it != singlegems.end(); it++)
    {
        m1.insert(make_pair(*it, cou++));
    }
    for (int i = 0; i < gems.size(); i++)
    {
        if (arr[m1[gems[i]]] == -1)
        {
            cnt++;
        }
        arr[m1[gems[i]]] = i;
        tmp[m1[gems[i]]] = i;
        if (cnt == size)
        {
            //tmp = arr;
            for (int l = 0; l < size; l++)
            {
                minre = min(minre, tmp[l]);
                maxre = max(maxre, tmp[l]);
            }
            //res = tmp.back() - tmp.front();
            res = maxre - minre;
            if (mini > res)
            {
                mini = res;
                answer.clear();
                answer.push_back(minre+1);
                answer.push_back(maxre+1);

                //answer.push_back(tmp.front()+1);
                //answer.push_back(tmp.back()+1);
                tmp.clear();
            }
            minre = 987654321;
            maxre = 0;
        }
    }
    return answer;
}