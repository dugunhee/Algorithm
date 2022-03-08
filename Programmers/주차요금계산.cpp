#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
map<string,string> in;
map<string,long long> price;
map<string,double> tot;
int T,F,PT,PF;
void calPrice(string numstr,double total_time){
    if(total_time<=T){
        price[numstr] += F;
        total_time-=T;
    }
    if(total_time>0){
        price[numstr] += F;
        total_time -= T;
        int tt = (int)ceil(total_time / (double)PT);
        long long ans = (long long)(tt * PF);
        price[numstr] += ans;
    }
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    T = fees[0];
    F = fees[1];
    PT = fees[2];
    PF = fees[3];
    for(int i=0;i<records.size();i++){
        int idx = records[i].find(" ",0);
        string time = records[i].substr(0,idx);
        int nidx = records[i].find(" ",idx+1);
        string numstr = records[i].substr(idx+1,nidx-idx-1);
        string inout = records[i].substr(nidx+1);
        if(inout == "IN"){
            in[numstr] = time;
            if(price.find(numstr)!=price.end())price[numstr] = 0;
        }
        else if(inout == "OUT"){
            int ih,im,oh,om;
            string t = in[numstr];
            ih = stoi(t.substr(0,2));
            im = stoi(t.substr(3,2));
            oh = stoi(time.substr(0,2));
            om = stoi(time.substr(3,2));

            // calPrice(numstr,ih,im,oh,om);
            if(tot.find(numstr)!=tot.end())tot[numstr] += oh*60+om - (ih*60+im);
            else tot[numstr] = oh*60+om - (ih*60+im);
            in.erase(numstr);
        }
    }
    for(auto it=in.begin();it != in.end();it++){
        int ih,im,oh,om;
        ih = stoi(it->second.substr(0,2));
        im = stoi(it->second.substr(3,2));
        oh = 23;
        om = 59;
        if(tot.find(it->first)!=tot.end())tot[it->first] += oh*60+om - (ih*60+im);
        else tot[it->first] = oh*60+om - (ih*60+im);
    }
    for(auto it=tot.begin();it != tot.end();it++){
        calPrice(it->first,it->second);
    }
    
    for(auto it=price.begin();it != price.end();it++){
        answer.push_back(it->second);
    }
    return answer;
}