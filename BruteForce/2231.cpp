#include<iostream>

using namespace std;

int main()
{
    int N;
    int tmp;
    int sum=0;
    int cnt=0;
    cin>>N;
    for(int i=1; i<N;i++)
    {
        sum = 0;
        tmp = i;
        while(tmp != 0)
        {
            sum += tmp%10;
            tmp /= 10;
        }
        sum += i;
        if(sum == N){
            cout<<i<<endl;
            cnt++;
            break;
        }
    }
    if(cnt == 0) cout<<0<<endl;
}