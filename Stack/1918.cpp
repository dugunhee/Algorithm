#include<iostream>
#include<string>
#include<stack>
using namespace std;
stack<char> st;
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    string input;
    cin>>input;
    char ch;
    int size = input.length();
    //cout<<size<<endl;
    int i;
    for(i=0;i<size;i++)
    {
        ch = input.at(i);
        //cout<<i<<endl;
        
        if(ch != '+' && ch != '-' && ch != '*' && ch!='/' && ch!='(' && ch != ')')
        {
            cout<<ch;
        }
        else
        {
            if(st.empty()) st.push(ch);
            else{
                if(ch == ')')
                {
                    while(st.top() != '('){
                        cout<<st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else if(ch == '+' || ch == '-'){
                    while(!st.empty()){
                        if(st.top() == '(')break;
                        cout<<st.top();
                        st.pop();
                    }
                    st.push(ch);
                }
                else if(ch == '*'||ch == '/'){
                    if(st.empty()) st.push(ch);
                    else{
                        while(!st.empty()){
                            if(st.top() == '*' || st.top() == '/'){
                                cout<<st.top();
                                st.pop();
                            }
                            else if(st.top() == '+' || st.top() == '-' || st.top() == '(')
                            {
                                st.push(ch);
                                break;
                            }
                        }
                        if(st.empty())st.push(ch);
                    }
                }
                else if(ch == '(') st.push(ch);
            }
        }
        if(i == size - 1){
                if(st.empty())break;
                else{
                while(!st.empty()){
                    cout<<st.top();
                    st.pop();
                }
                break;
                }
            }
    }
}