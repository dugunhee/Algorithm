#include <iostream>

using namespace std;
int roundA,roundB;
int round(int X)
{
    if(X%2 == 0)
    {
        return X/2;
    }
    else
    {
        return (X/2+1);
    }
}
int solution(int n, int a, int b)
{
    int answer = 0;
    roundA = -1;
    roundB = -2;
    while(a != b)
    {
        a = round(a);
        b = round(b);
        answer++;
    }
    return answer;
}