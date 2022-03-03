#include<iostream>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
int N,M;//사람 수, 파티 수
set<int> T;
int people[51];
vector<int> party[51];
void init(){
    memset(people,0,sizeof(people));
    for(int i=0;i<51;i++){
        party[i].clear();
    }
    T.clear();
}
int main(){
    init();
    cin>>N>>M;
    int num = 0;
    cin>>num;//진실 아는 수
    for(int i=0;i<num;i++){
        int truth;
        cin>>truth;
        people[truth] = 1;
        T.insert(truth);
    }
    int tmp;
    for(int i=0;i<M;i++){
        cin>>num;
        for(int j=0;j<num;j++){
            cin>>tmp;
            party[i].push_back(tmp);
        }
    }
    int cnt=1, flag=0, flag2=0;
    while(cnt--){
        flag2=0;
        for(int i=0;i<M;i++){
            flag = 0;
            for(int j=0;j<party[i].size();j++){
                if(T.find(party[i][j]) != T.end()){
                    flag = 1;
                }
            }
            if(flag == 1){
                for(int j=0;j<party[i].size();j++){
                    if(T.find(party[i][j]) == T.end()){
                        T.insert(party[i][j]);
                        flag2 = 1;
                    }
                }
            }
        }
        if(flag2 == 1) cnt++;
    }
    
    int ans=M;
    for(int i=0;i<M;i++){
        for(int j=0;j<party[i].size();j++){
            if(T.find(party[i][j]) != T.end()){
                ans--;
                break;
            }
        }
    }
    cout<<ans<<endl;
}