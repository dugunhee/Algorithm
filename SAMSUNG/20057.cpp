#include<iostream>

using namespace std;
int N;
int arr[501][501];
int d[4] = {0,1,2,3};
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int xdx[4][10] = { { -1, 1, -1, 1, -1, 1, -2, 2, 0, 0 },{ -1, 1, -1, 1, -1, 1, -2, 2, 0, 0 },
                  { 0, 0, 1, 1, 2, 2, 1, 1, 3, 2}, { 0, 0, -1, -1, -2, -2, -1, -1, -3, -2} };
int ydy[4][10] = { { 0, 0, 1, 1, 2, 2, 1, 1, 3, 2}, { 0, 0, -1, -1, -2, -2, -1, -1, -3, -2},
                  { -1, 1, -1, 1, -1, 1, -2, 2, 0, 0}, {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0} };
int percent[9] = {1,1,2,2,7,7,10,10,5};
long long outside_sand;
void move_sand(int x,int y){
    //d==0 left-> r: up3 , l: down1, back : right2
    //d==1 down-> r: left0, l: righ2t, back : up3
    //d==2 right-> r:down1, l: up3, back: left0
    //d==3 up-> r: right2, l:left0, back: down1
    long long sand = arr[x][y];
      

}
void tornado(int x, int y){
    int cnt=0;
    int len=1;
    while(1){
        for(int i=0;i<4;i++){
            if(i%2 == 0)len++;
            for(int j=0;j<len;j++){
                if(x == 0 && y == 0) return;
                int nx = x + dx[i];
                int ny = y + dy[i];
                move_sand(nx,ny);
                x = nx;
                y = ny;
            }
        }
    }
}
int main()
{
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }
    tornado(N/2,N/2);
    cout<<outside_sand<<'\n';
}