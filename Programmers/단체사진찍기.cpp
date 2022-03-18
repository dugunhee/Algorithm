#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
vector<char> vec = {'A','C','F','J','M','N','R','T'};
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    int findex, sindex;
    char first, second;
    int fcnt;
    int num;
    do{
        fcnt = 0;
        for(int k=0;k<n;k++)
        {
            findex = -1;
            sindex = -1;
            first = data[k][0];
            second = data[k][2];
            num = data[k][4]-'0';
            for(int i=0;i<vec.size();i++)
            {
                if(vec[i] == first)
                {
                    findex = i;
                }
                else if(vec[i] == second){
                    sindex = i;
                }
            }
            if(findex!=-1 && sindex!=-1)
            {
                if(data[k][3] == '=')
                {
                    if(((int)abs(findex-sindex)-1) == num) fcnt++;
                }
                else if(data[k][3] == '>')
                {
                    if(((int)abs(findex-sindex)-1) > num) fcnt++;
                }
                else if(data[k][3] == '<')
                {
                    if(((int)abs(findex-sindex)-1) < num) fcnt++;
                }
            }
        }
        if(fcnt == n) answer++;
    }while(next_permutation(vec.begin(), vec.end()));
    cout<<answer<<endl;
    return answer;
}