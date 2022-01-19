#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<math.h>
using namespace std;

vector<pair<int,int> > vec;
int main()
{
    int N;
    int ans=0;
    int a,b;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>a>>b;
        vec.push_back(make_pair(a,b));
        if(i>0){
            ans += (abs(vec[i].first-vec[i-1].first) + abs(vec[i].second-vec[i-1].second));
        }
    }
    cout<<ans<<endl;
    int maxi=0;
    for(int i=1;i<N-1;i++)
    {
        int tmp = (abs(vec[i].first-vec[i-1].first) + abs(vec[i].second-vec[i-1].second) + abs(vec[i+1].first-vec[i].first) + abs(vec[i+1].second-vec[i].second));
        maxi = max(maxi, tmp - (abs(vec[i+1].first-vec[i-1].first) + abs(vec[i+1].second-vec[i-1].second)));
    }
    cout<<ans-maxi<<endl;
}