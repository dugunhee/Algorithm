#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<char> st;
int main()
{
    int n;
    cin>>n;
    int ans=0;
    string str;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        int size = str.length();
        for(int j=0;j<size;j++)
        {
            if(st.empty()) st.push(str.at(j));
            else{
                if(st.top() == str.at(j)){
                    st.pop();
                }
                else st.push(str.at(j));
            }
        }  
        if(st.size() == 0) ans++;
        else{
            while(!st.empty())st.pop();
        }
    }
    cout<<ans<<endl;
}