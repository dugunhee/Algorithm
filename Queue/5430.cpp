#include<iostream>
#include<cstdio>
#include<string>
#include<deque>
using namespace std;
deque<int> dq;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    string cmd;
    int number;
    int reverse = 1;
    int n;
    char ch;
    int flag=0;
    while(T--)
    {
        //dq.erase(dq.begin(),dq.end());
        flag= 0;
        reverse = 1;
        cin>>cmd>>n;
        //cin>>number;
        
        cin>>ch;
        for(int i=0;i<n;i++)
        {   
            cin>>number;
            dq.push_back(number);
            char tr;
            cin>>tr;    
        }
        if(n == 0) cin>>ch;
        for(int i=0;i<cmd.size();i++)
        {
            if(cmd.at(i) == 'R'){
                reverse *= -1;
            }
            else if(cmd.at(i) == 'D'){
                if(dq.empty()){ 
                    cout<<"error"<<endl;
                    flag = 1;
                    break;
                }
                if(reverse == 1){
                    dq.pop_front();
                }
                else{
                    dq.pop_back();
                }
            }
        }
        if(flag==1)continue;
        cout<<'[';
        if(reverse == 1){
            if(dq.empty()){cout<<']'<<endl;
                continue;
            }
            while(!dq.empty()){
                if(dq.size()==1) cout<<dq.front()<<']'<<endl;
                else cout<<dq.front()<<',';
                dq.pop_front();
            }
        }
        else if(reverse == -1){
            if(dq.empty()){cout<<']'<<endl;
                continue;
            }
            while(!dq.empty()){
                if(dq.size()==1) cout<<dq.back()<<']'<<endl;
                else cout<<dq.back()<<',';
                dq.pop_back();
            }
            
        }
    }
}