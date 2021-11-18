#include<iostream>
#include<string>
using namespace std;
int main(){
    int arr[26] = {0,};
    string str = "dbbaaaac";
    for(int i=0;i<str.size();i++)
    {
        if(arr[str[i]-'a'] == 0){
            arr[str[i]-'a'] = 1;
        }
        else continue;
    }
    string ans = "";
    for(int i=0;i<26;i++)
    {
        if(arr[i]!=0) ans += ('a'+i);
    }
    cout<<ans<<endl;
}