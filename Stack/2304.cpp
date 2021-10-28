#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
stack<int> st;
vector<pair<int,int> > vec;
int main()
{
    int n;
    cin>>n;
    pair<int,int> p;
    int f,s;
    for(int i=0;i<n;i++)
    {
        cin>>f>>s;
        p = make_pair(f,s);
        vec.push_back(p);
    }
    sort(vec.begin(),vec.end());
    int tmp;
    tmp = vec[0].first;
    st.push(vec[0].second);
    int len;
    int ans=0;
    int m=0;
    for(int i=1;i<n;i++)
    {
        if(st.top()>=vec[i].second){
            continue;
        }
        else{
            len = vec[i].first-tmp;
            //cout<<len<<endl;
            ans += st.top()*len;
            tmp = vec[i].first;
            st.pop();
            st.push(vec[i].second);
        }
    }
    while(!st.empty()){
        st.pop();
    }
    tmp = vec[n-1].first;
    st.push(vec[n-1].second);
    for(int i=n-2;i>=0;i--)
    {
        if(st.top()>vec[i].second){
            continue;
        }
        else{
            len = tmp-vec[i].first;
            //cout<<len<<endl;
            ans += st.top()*len;
            tmp = vec[i].first;
            st.pop();
            st.push(vec[i].second);
        }
    }
    ans+=st.top();
    cout<<ans<<endl;
}