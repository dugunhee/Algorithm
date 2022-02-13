#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int> > picture) {
    queue<pair<int, int> > q;
    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };
    int visited[100][100];
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<int> answer(2);
    int i, j;
    int cnt = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            int nx=0, ny = 0;
            int x=0, y=0;
            cnt = 0;
            if (visited[i][j] == 0 && picture[i][j] != 0)
            {
                q.push({ i,j });
                visited[i][j] = 1;
                number_of_area++;
                cnt++;
                while (!q.empty())
                {
                    x = q.front().first;
                    y = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        nx = x + dx[k];
                        ny = y + dy[k];
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n && visited[nx][ny] == 0 &&picture[nx][ny] == picture[x][y])
                        {
                            q.push(make_pair(nx, ny));
                            cnt++;
                            visited[nx][ny] = 1;
                        }
                    }
                }
                max_size_of_one_area = max(cnt, max_size_of_one_area);
            }
        }
    }
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}