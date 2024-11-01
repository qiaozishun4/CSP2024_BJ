#include<fstream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
vector<int>arr;
map<int,pair<int,int>>arr2;
int ans=0;
ifstream cin("duel.in");
ofstream cout("duel.out");
inline int su(pair<int,int> n){return n.first+n.second;}
bool chk()
{
    int idxlast=-1;
    bool ret=false;
    for(auto it=arr2.begin();it!=arr2.end();it++)
    {

        if(idxlast!=-1)
        {
            int t=min(su(arr2[idxlast]),it->second.first);
            int t1=min(t,arr2[idxlast].first);
            (it->second.first)-=t;
            (it->second.second)+=t;

            arr2[idxlast].first-=t1;
            arr2[idxlast].second-=t-t1;

            if(t)ret=true;
        }
        if(su(it->second)==0)
        {
            arr2.erase(it->first);
            return true;
        }
        idxlast=it->first;
    }
    return ret;
}
int main()
{
    int n;cin>>n;
    //ans=n;
    arr.resize(n);
    for(int& num:arr)
        cin>>num,arr2[num].first++;
    while(chk());//printf("%d\n",ans);
    for(auto it=arr2.begin();it!=arr2.end();it++)ans+=su(it->second);
    cout<<ans;
    return 0;
}
