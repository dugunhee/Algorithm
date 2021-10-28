#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<string> st;

int main()
{
    string mstr;
    int flag=0;
    while(1){
        flag = 0;
        char ch;
        getline(cin,mstr);
        if(mstr == "#")break;
        else{
            int size= mstr.length();
            int i;
            string tmp="";
            for(i=0;i<size;i++)
            {
                if(mstr.at(i) == '<')
                {
                    i++;
                    if(mstr.at(i) == '/')
                    {
                        i++;
                        while(mstr.at(i) != '>' && mstr.at(i) != ' ')
                        {
                            tmp += mstr.at(i);
                            i++;
                        }
                        //cout<<"tmp: "<<tmp<<endl;
                        if(st.empty()){
                            flag = 1;
                            break;
                        }
                        else{
                        if(st.top() == tmp){
                            st.pop();
                        }
                        else{
                            while(!st.empty()){
                                st.pop();
                            }
                            flag = 1;
                            break;
                        }
                        }
                        tmp = "";
                    }
                    else{
                        while(mstr.at(i) !='>'&& mstr.at(i) != ' ')
                        {
                            tmp+= mstr.at(i);
                            i++;
                        }
                        //cout<<"tmp: "<<tmp<<endl;
                        if(tmp == "br"){
                            tmp="";
                            continue;
                        }
                        st.push(tmp);
                        tmp ="";
                    }
                }
            }
            if(flag == 1){
                cout<<"illegal"<<endl;
                continue;
            }
            if(st.empty()){
                cout<<"legal"<<endl;
            }
            else{
                cout<<"illegal"<<endl;
                while(!st.empty()) st.pop();
            }
        }
    }
}