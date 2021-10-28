#include<iostream>
#include<string>
#include<queue>
using namespace std;
queue<int> q;
int main()
{
    int n;
    string cmd;
    int num;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>cmd;
        if(cmd == "push"){
            cin>>num;
            q.push(num);
        }
        else if(cmd == "pop"){
            if(q.empty()){cout<<-1<<endl; continue;}
            cout<<q.front()<<endl;
            q.pop();
        }
        else if(cmd == "size"){
            cout<<q.size()<<endl;
        }
        else if(cmd == "empty"){
            cout<<q.empty()<<endl;
        }
        else if(cmd == "front"){
            if(q.empty()){cout<<-1<<endl; continue;}
            cout<<q.front()<<endl;
        }
        else if(cmd == "back"){
            if(q.empty()){cout<<-1<<endl; continue;}
            cout<<q.back()<<endl;
        }
    }
    return 0;
}