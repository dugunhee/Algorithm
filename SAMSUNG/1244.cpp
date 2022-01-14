#include<iostream>

using namespace std;
int switch_num;
int sex;
int switchs[102];
int main(){
    int people;
    int number;
    cin>>switch_num;
    for(int i=1;i<=switch_num;i++){
        cin>>switchs[i];
    }
    cin>>people;
    
    for(int i=0;i<people;i++)
    {
        cin>>sex;
        cin>>number;
        if(sex == 1){
            for(int j=number;j<=switch_num;j+=number){
                switchs[j]*=-1;
                switchs[j]+=1;
            }
        }
        else if(sex == 2){
            int k=0;
            while(1){
                k++;
                if(k==1){
                    switchs[number]*=-1;
                    switchs[number]+=1;
                }
                if(number-k<=0 || number+k>switch_num) break;
                if(switchs[number-k] == switchs[number+k]){
                    switchs[number-k]*=-1;
                    switchs[number-k]+=1;
                    switchs[number+k]*=-1;
                    switchs[number+k]+=1;
                }
                else break;
            }
        }
    }
    for(int i=1;i<=switch_num;i++){
        cout<<switchs[i]<<' ';
    }
    cout<<endl;
}