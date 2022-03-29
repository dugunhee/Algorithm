#include<iostream>
#include<algorithm>
#include<string.h>
#define END 32
using namespace std;

int idx[50] = {1,2,3,4,5, 6,7,8,9,10, 11,12,13,14,15, 16,17,18,19,20, END,22,23,24,30, 26,27,24,29,24, 31,20,END};
int score[50] = {0, 2,4,6,8,10, 12,14,16,18,20, 22,24,26,28,30, 32,34,36,38,40, 13,16,19,25,28, 27,26,22,24,30, 35,0};
int dice[10];
int horse[4] = {0,};
int ban[4] = {0,};
int maxi = 0;
int move(int loc, int dist){
    if(loc == END) return loc;
    for(int i=0;i<dist;i++){
        if(i==0){
            if(loc == 5){ loc = 21; continue; }
            else if(loc == 10){ loc = 28; continue; }
            else if(loc == 15){ loc = 25; continue; }
        }
        loc = idx[loc];
        if(loc == END)break;
    }
    return loc;
}
void dfs(int sc, int d){
    if(d == 10){
        if(maxi<sc){
            maxi = max(maxi,sc);
        }
        return;
    }
    for(int i=0;i<4;i++){
        int flag = 0;
        if(horse[i] == END) continue;
        int dist = dice[d];
        int prev = horse[i];
        int mov = move(horse[i],dist);
        horse[i] = mov;
        //이동을 마친 칸에 말이 있으면 고를 수 없음
        for(int j=0;j<4;j++){
            if(j==i)continue;
            if(horse[j] != END && horse[j] == horse[i]){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            horse[i] = prev;
            continue;
        }
        sc += score[mov];
        dfs(sc, d+1);
        sc -= score[mov];
        horse[i] = prev;
        // memset(ban,0,sizeof(ban));
    }
}
int main(){
    for(int i=0;i<10;i++){
        cin>>dice[i];
    }
    dfs(0,0);
    cout<<maxi<<'\n';
}