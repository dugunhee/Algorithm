#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string a, string b)
{
    string tmpa = a;
    string tmpb = b;
    string heada="";
    string headb="";
    int flag =0 ;
    for(int i=0;;i++)
    {
        if(tmpa[i]>='0' && tmpa[i]<='9'){
            flag = i;
            break;
        }
        if(tmpa[i]>='A' && tmpa[i]<='Z') tmpa[i]+=32;
        heada += tmpa[i];
    }
    int numa=0;
    int numb=0;
    string nastr="";
    string nbstr="";
    for(int i=flag;;i++)
    {
        if((tmpa[i]>='a' && tmpa[i]<='z')||(tmpa[i]>='A' && tmpa[i]>='Z')) break;
        nastr+=tmpa[i];
    }
    numa = stoi(nastr);
    for(int i=0;;i++)
    {
        if(tmpb[i]>='0' && tmpb[i]<='9'){
            flag = i;
            break;
        }
        if(tmpb[i]>='A' && tmpb[i]<='Z') tmpb[i]+=32;
        headb += tmpb[i];
    }
    for(int i=flag;;i++)
    {
        if((tmpb[i]>='a' && tmpb[i]<='z')||(tmpb[i]>='A' && tmpb[i]>='Z')) break;
        nbstr+=tmpb[i];
    }
    numb = stoi(nbstr);
    if(heada == headb){
        return numa<numb;
    }
    else return heada<headb;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    stable_sort(files.begin(),files.end(),cmp);
    for(int i=0;i<files.size();i++)
    {
        answer.push_back(files[i]);
    }
    return answer;
}