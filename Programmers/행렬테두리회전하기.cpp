#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
deque<int> deq;
int board[101][101];
vector<int> solution(int rows, int columns, vector<vector<int> > queries) {
    vector<int> answer;
    int i,j;
    int num=1;
    for(i=1;i<=rows;i++)
    {
        for(j=1;j<=columns;j++)
        {
            board[i][j] = num++;
        }
    }
    for(i=0;i<queries.size();i++)
    {
        int x1 = queries[i][0];
        int y1 = queries[i][1];
        int x2 = queries[i][2];
        int y2 = queries[i][3];
        int mini = 987654321;
        for(j=y1;j<=y2;j++)deq.push_back(board[x1][j]);
        for(j=x1+1;j<=x2;j++)deq.push_back(board[j][y2]);
        for(j=y2-1;j>=y1;j--)deq.push_back(board[x2][j]);
        for(j=x2-1;j>x1;j--)deq.push_back(board[j][y1]);
        //deq.push_front(board[x1][y1]);
        for(j=0;j<deq.size();j++)
        {
            mini = min(mini,deq[j]);
        }
        for(j=y1+1;j<=y2;j++){
            board[x1][j] = deq.front();
            deq.pop_front();
        }
        for(j=x1+1;j<=x2;j++){
            board[j][y2] = deq.front();
            deq.pop_front();
        }
        for(j=y2-1;j>=y1;j--){
            board[x2][j] = deq.front();
            deq.pop_front();
        }
        for(j=x2-1;j>x1;j--){
            board[j][y1] = deq.front();
            deq.pop_front();
        }
        board[x1][y1] = deq.front();
        deq.pop_front();
        answer.push_back(mini);
    }
    return answer;
}