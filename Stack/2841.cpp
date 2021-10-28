#include<iostream>
#include<stack>
using namespace std;
stack<int> st[7];
int main()
{
    int n,p;
    cin>>n>>p;
    int line, num;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>line>>num;
        if(st[line].empty()){
            st[line].push(num);
            ans++;
        }
        else{
            while(!st[line].empty()&&st[line].top()>num)
            {
                st[line].pop();
                ans++;
            }
            if(st[line].empty()){
                st[line].push(num);
                ans++;
                continue;
            }
            else{
                if(st[line].top() == num)continue;
                else{
                    st[line].push(num);
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}