#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int i,j;
    int size= progresses.size();
    vector<int> work;
    for(i=0;i<size;i++)
    { 
        int tmp = 100-progresses[i];
        if(tmp%speeds[i]==0) work.push_back(tmp/speeds[i]);
        else{
            work.push_back(tmp/speeds[i] + 1);
        }
    }
    int cnt;
    int past;
    for(i=0;i<size;i++)
    {
        if(i==0) {
            past = work[i];
            cnt = 1;
            continue;
        }
        if(past<work[i]){
            past = work[i];
            answer.push_back(cnt);
            cnt = 1;
        }
        else cnt++;
        if(i == size-1) answer.push_back(cnt);
    }
    return answer;
}