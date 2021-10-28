#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
stack<long long> st;
long long histo[100001];
int main()
{
    int n;
    int i;
    cin>>n;
    long long ans=0;
    long long len;
    for(int i=0;i<n;i++)
    {
        cin>>histo[i];
    }
    long long tmp;
    for(int i=0;i<n;i++)
    {
        while(!st.empty()&&histo[i]<histo[st.top()]){
            tmp = st.top();
            st.pop();
            if(st.empty()) len = i;
            else len = i-st.top()-1;
            ans = max(ans,histo[tmp]*len);
        }
        st.push(i);
    }
    while(!st.empty())
    {
        tmp = st.top();
        st.pop();
        if(st.empty())len = n;
        else len = n-st.top()-1;
        ans = max(ans,histo[tmp]*len);
    }
    cout<<ans;
}