#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> vec;
int main()
{
    int sum = 0;
    int tmp;
    int flag1, flag2;
    int end=0;
    for(int i=0;i<9;i++)
    {
        cin >> tmp;
        vec.push_back(tmp);
        sum += tmp;
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(i == j) continue;
            if(sum - vec[i] - vec[j] == 100){
                flag1 = i;
                flag2 = j;
                end = 1;
                break;
            };
        }
        if(end == 1)break;
    }
    for(int i=0;i<9;i++)
    {
        if(i!= flag1 && i !=flag2){
            cout << vec[i] <<endl;
        }
    }
}
