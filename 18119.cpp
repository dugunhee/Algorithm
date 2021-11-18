#include<iostream>
#include<string>
#include<vector>
using namespace std;
int N,M;
vector<string> vec;
vector<int> res;
int arr[100001]={0, };
int alphabet;
int main()
{
    int i,j;
    cin>>N>>M;
    string str;
    for(i=0;i<N;i++)
    {
        cin>>str;
        vec.push_back(str);
        for(j=0;j<vec[i].size();j++)
        {
            arr[i] |= (1<< (vec[i][j]-'a'));
        }
    }
    for(i=0;i<26;i++)alphabet += 1<<i;
    int op;
    char ch;
    
    for(i=0;i<M;i++)
    {
        cin>>op>>ch;
        if(op==1) alphabet ^= (1<<(ch-'a'));
        else if(op==2) alphabet |= (1<<(ch-'a'));
        int ans = vec.size();
        for(j=0;j<N;j++)
        {
            if((arr[j] & alphabet) != arr[j]) ans--;
        }
        res.push_back(ans);
    }
    for(i=0;i<res.size();i++)
    {
        cout<<res[i]<<endl;
    }
}
