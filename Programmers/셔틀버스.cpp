#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    sort(timetable.begin(),timetable.end());
    for(int i=0;i<timetable.size();i++)
    {
        cout<<timetable[i]<<' ';
    }cout<<endl;
    string start_time = "09:00";
    int flag = 0;
    while(1)
    {
        int people1 = m;
        string maxi = "00:00";
        for(int i=flag;i<timetable.size();i++)
        {
            if(timetable[i]<=start_time)
            {
                people1--;
                if(maxi<timetable[i]) maxi = timetable[i];
                cout<<maxi<<endl;
                if(people1 == 0){
                    flag = i+1;
                    cout<<flag<<endl;
                    break;
                }
            }
            else {flag = i;break;}
        }
        int fhh = stoi(start_time.substr(0,2));
        int fmm = stoi(start_time.substr(3,2));
        if(fmm+t>=60){
            fhh+=1;
            fmm = fmm+t-60;
        }
        else fmm+=t;
        if(n==1 && people1 == 0){
            int ahh = stoi(maxi.substr(0,2));
            int amm = stoi(maxi.substr(3,2));
            amm -= 1;
            if(amm<0){
                amm = amm+60;
                ahh-=1;
            }
            maxi = "";
            if(ahh/10==0)maxi+='0';
            maxi+=to_string(ahh);
            maxi+=':';
            if(amm/10==0)maxi+='0';
            maxi+=to_string(amm);
            answer = maxi;
            break;
        }
        if(n == 1 && people1>0){
            answer = start_time;
            break;
        }
        string tmp = "";
        if(fhh/10 == 0) tmp+='0';
        tmp += to_string(fhh);
        tmp += ':';
        if(fmm/10==0) tmp+='0';
        tmp += to_string(fmm);
        start_time = tmp;
        n--;
    }
    return answer;
}