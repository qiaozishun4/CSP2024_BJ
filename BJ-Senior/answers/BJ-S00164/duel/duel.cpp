#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
map<int,int> mp;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int i,j,k,x;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>x;
        mp[x]++;
    }
    for (auto kv:mp)
        ans=max(ans,kv.second);
    cout<<ans<<endl;
    return 0;
}
