#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n,r,ans;
map<int,int> mp,mp2;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>r;
        mp[r]++,mp2[r]++;
    }
    auto be=mp.begin();
    mp[be->first]=0;
    be++;
    for(auto it=be;it!=mp.end();it++)
    {
        auto it2=it;
        it2--;
        mp[it->first]+=it2->second+mp2[it2->first],mp[it->first]-=mp2[it->first];
    }
    for(auto it=be;it!=mp.end();it++)
    {
        int mini=min(mp2[it->fi],it->se-ans);
        ans+=mini;
    }
    cout<<n-ans;
    return 0;
}