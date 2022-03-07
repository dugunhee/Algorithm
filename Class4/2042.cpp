#include<iostream>
#include<string.h>
using namespace std;
int N,M,K;
long long tree[3000001];
int start;
int getIdx(int n)//배열의 시작점을 찾는 함수 -> 2를 거듭제곱하면서 크기를 늘려본다. 만약 N보다 크거나 같아지면 stop.
{
    int tmp=1;
    while(tmp<n){
        tmp <<= 1;
    }
    return tmp;
}
void init(){
    memset(tree,0,sizeof(tree));
}
void update(int i, long long cost){//bottom up 방식으로 각 노드에 더해준다.
    int idx = start + i -1;
    long long diff = cost - tree[idx];
    while(idx>=1){
        tree[idx] += diff;
        idx/=2;
    }
}
long long sum(int a, int b){
    int st = start + a - 1;
    int nd = start + b - 1;
    long long res = 0;
    while(st<=nd){//st는 오른쪽일 때 결과에 더하고 ++, nd는 왼쪽일 때 결과에 더하고 --.
        if(st%2 == 1){
            res += tree[st];
            st++;
        }
        if(nd%2 == 0){
            res += tree[nd];
            nd--;
        }
        st/=2;
        nd/=2;
    }
    return res;
}
int main()
{
    cin>>N>>M>>K;
    init();
    start = getIdx(N);
    long long num;
    for(int i=0;i<N;i++){
        cin>>num;
        update(i+1,num);
    }
    int a,b;
    long long c;
    for(int i=0;i<M+K;i++){
        cin>>a>>b>>c;
        if(a == 1){
            update(b,c);
        }
        else if(a == 2){
            cout<<sum(b,c)<<endl;
        }
    }
}