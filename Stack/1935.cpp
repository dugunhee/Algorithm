#include<iostream>
#include<cstdio>
#include<stack>
#include<string>
using namespace std;
double alpha[26];
stack<double> st;
int main()
{
    int n;
    cin>>n;
    string input;
    cin>>input;
    int i;
    for(i=0;i<n;i++){
        cin>>alpha[i];
    }
    int size = input.length();
    char ch;
    for(i=0;i<size;i++){
        ch = input.at(i);
        if(ch == '+'||ch=='-'||ch=='*'||ch=='/'){
            double f,s;
            s = st.top();
            st.pop();
            f = st.top();
            st.pop();
            if(ch=='+') st.push(f+s);
            else if(ch=='-')st.push(f-s);
            else if(ch=='*')st.push(f*s);
            else if(ch=='/')st.push(f/s);
        }
        else{
            //cout<<alpha[(int)ch-65]<<endl;
            st.push(alpha[(int)ch-65]);
        }
    }
    printf("%.2lf\n",st.top());
}