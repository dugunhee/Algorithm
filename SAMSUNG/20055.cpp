#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
deque<int> belt;
deque<int> robot;
int N,k;
int findzero()
{
    int i,j;
    int cnt = 0;
    for(i=0;i<2*N;i++)
    {
        if(belt[i] == 0)cnt++;
    }
    return cnt;
}
int main()
{
    cin>>N>>k;
    int i,j;
    int ability=0;
    for(i=0;i<2*N;i++){
        cin>>ability;
        belt.push_back(ability);
        robot.push_back(0);
    }
    int stage = 1;
    int up = 0;
    int down = N-1;
    while(1)
    {
        //1 
        belt.push_front(belt.back());
        belt.pop_back();
        robot.push_front(robot.back());
        robot.pop_back();
        //2
        for(i=N-1;i>=0;i--){
            if(i==N-1){
                robot[i] = 0;
                continue;
            }
            if(robot[i] == 1){
                if(belt[i+1]>0 && robot[i+1] == 0){
                    robot[i] = 0;
                    robot[i+1] = 1;
                    if(i+1 == N-1)robot[i+1] = 0;
                    belt[i+1]--;
                }
            }
        }
        //3
        if(belt[0]!=0){
            robot[0] = 1;
            belt[0]--;
        }
        if(findzero()>=k)break;
        stage++;
        
    }
    cout<<stage<<endl;
}