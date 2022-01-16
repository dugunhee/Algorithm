#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> number;
int weight[10];
int main(){
    int N,K;
    int ans=0;
    cin>>N>>K;
    for(int i=1;i<=N;i++)
    {
        cin>>weight[i];
        number.push_back(i);
    }
    do{
        int total = 500;
        int flag = 0;
        for(int i=0;i<number.size();i++){
            total += weight[number[i]];
            total -= K;
            if(total<500){
                flag = 1;
                break;
            }
       }
       if(flag != 1)ans++;
    }while(next_permutation(number.begin(),number.end()));
    cout<<ans<<endl;
}