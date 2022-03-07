#include<iostream>

using namespace std;
long long A,B,C;
long long cal(int a, int b){
    if(b == 0) return 1;
    if(b == 1) return a%C;
    else{
        if(b%2 == 0){
            long long tmp = cal(a,b/2);
            return tmp*tmp%C;
        }
        else{
            return a*cal(a,b-1)%C;
        }
    }
}
int main()
{
    cin>>A>>B>>C;
    cout<<cal(A,B);
}