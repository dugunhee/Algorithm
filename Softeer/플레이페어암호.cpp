#include<iostream>
#include<string>
#include<vector>
#include<string.h>
#include<utility>
using namespace std;
string msg, key;
vector<char> vec;
char keyMap[5][5];
int visit[26];
pair<int,int> dir[26];
int main(int argc, char** argv)
{
	memset(visit,0,sizeof(visit));
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>msg>>key;
	for(int i=0;i<key.size();i++){
		if(visit[key[i]-'A'] == 1) continue;
		else{
			vec.push_back(key[i]);
			visit[key[i]-'A'] = 1;
		}
	}
	for(int i=0;i<26;i++){
		if(('A'+i) == 'J') continue;
		if(visit[i] == 0) vec.push_back('A'+i);
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			keyMap[i][j] = vec[i*5+j];
			dir[vec[i*5+j]-'A'] = make_pair(i,j);
		}
	}
	while(1){
		int flag = 0;
		for(int i=0;i<msg.size()-1;i+=2){
			if(msg[i] == msg[i+1]){
				string fir = msg.substr(0,i+1);
				string sec = msg.substr(i+1);
				if(msg[i] != 'X'){
					fir += "X";
					fir += sec;
				}
				else{
					fir += "Q";
					fir += sec;
				}
				msg = fir;
				flag = 1;
			}
		}
		if(flag == 0){
			if(msg.size()%2 != 0) msg += "X";
			break;
		}
	}
	for(int i=0;i<msg.size()-1;i+=2){
		int ff = dir[msg[i]-'A'].first; 
		int fs = dir[msg[i]-'A'].second; 
		int sf = dir[msg[i+1]-'A'].first;
		int ss = dir[msg[i+1]-'A'].second;
		if(ff == sf){
			msg[i] = keyMap[ff][(fs+1)%5];
			msg[i+1] = keyMap[sf][(ss+1)%5];
		}
		else if(fs == ss){
			msg[i] = keyMap[(ff+1)%5][fs];
			msg[i+1] = keyMap[(sf+1)%5][ss];
		}
		else{
			msg[i] = keyMap[ff][ss];
			msg[i+1] = keyMap[sf][fs];
		}
	}
	cout<<msg<<'\n';
	return 0;
}