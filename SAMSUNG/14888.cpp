#include<iostream>
#include<algorithm>
using namespace std;
int N;
int num[21];
int op[21];
int per[21];
int main()
{
    cin>>N;
    int i,j;
    for(i=0;i<N;i++)
    {
        cin>>num[i];
    }
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    for(i=0;i<a;i++) op[i]=1;
    for(i=a;i<a+b;i++) op[i]=2;
    for(i=a+b;i<a+b+c;i++) op[i]=3;
    for(i=a+b+c;i<a+b+c+d;i++) op[i]=4;
    fill(per,per+20,0);
    int mi=1000000001,ma = -1000000001;
    do{
        int tmp = num[0];
        for(i=0;i<N-1;i++)
        {
            if(op[i] == 1) tmp+=num[i+1];
            else if(op[i] == 2) tmp -= num[i+1];
            else if(op[i] == 3) tmp *= num[i+1];
            else if(op[i] == 4) tmp /= num[i+1];
        }
        mi = min(mi,tmp);
        ma = max(ma,tmp);
    }while(next_permutation(op,op+N-1));
    cout<<ma<<endl;
    cout<<mi<<endl;
}