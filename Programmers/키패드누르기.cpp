#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
vector<char> answer;
int phone[4][3];
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int i;
    int LE = 10, RI = 12;
    int l, r;
    int Llen, Rlen;
    for (i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer.push_back('L');
            if (numbers[i] == 1) LE = 1;
            else if (numbers[i] == 4)LE = 4;
            else LE = 7;
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer.push_back('R');
            if (numbers[i] == 3) RI = 3;
            else if (numbers[i] == 6)RI = 6;
            else RI = 9;
        }
        else
        {
            if (numbers[i] == 0)numbers[i] = 11;
            l = (numbers[i] - 1) / 3;
            r = (numbers[i] - 1) % 3;
            Llen = abs((LE - 1) / 3 - l) + abs((LE - 1) % 3 - r);
            Rlen = abs((RI - 1) / 3 - l) + abs((RI - 1) % 3 - r);
            if (Llen == Rlen)
            {
                if (hand == "left")
                {
                    answer.push_back('L');
                    LE = numbers[i];
                }
                else if(hand == "right")
                {
                    answer.push_back('R');
                    RI = numbers[i];
                }
            }
            else if (Llen < Rlen)
            {
                answer.push_back('L');
                LE = numbers[i];
            }
            else if (Llen > Rlen)
            {
                answer.push_back('R');
                RI = numbers[i];
            }
        }
    }
    return answer;
}