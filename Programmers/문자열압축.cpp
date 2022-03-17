#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
char str[1001];
int solution(string s)
{
	int i, j;
	for (i = 0; i < s.length(); i++)
	{
		str[i] = s[i];
	}
	int mini = s.length();
	int answer = 0;
	int len = s.length();
	int cnt=1;
	for (i = 1; i <= len/2; i++)
	{
		answer = i;
		for (j = i; j < len; j += i)
		{
			if ( s.substr(j,i) == s.substr(j-i,i)) cnt++;
			else
			{
				if (cnt != 1)
				{
					answer += to_string(cnt).size();
				}
				if (len-j<i) answer += s.length() - j;
				else answer += i;
				cnt = 1;
			}
		}
		if (cnt != 1)
		{
			answer += to_string(cnt).size();
		}
		cout << i<<": "<< answer << '\n';
		mini = min(answer, mini);
		cnt = 1;
	}
	return mini;
}