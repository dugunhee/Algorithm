#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> m;
int solution(vector<vector<string> > clothes) {
    int answer = 0;
    for (int i = 0; i < clothes.size(); i++)
    {
        if (m.count(clothes[i][1]) == 0)
        {
            m.insert(make_pair(clothes[i][1], 1));
            continue;
        }
        auto it = m.find(clothes[i][1]);
        it->second += 1;
    }
    int tmp = 1;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << '\n';
        tmp *= (it->second+1);
    }
    answer = tmp - 1;
    return answer;
}