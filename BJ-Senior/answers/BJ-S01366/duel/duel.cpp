#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct AC
{
    ll id,r;
    bool vis;
};
ll n,ans,x,l,cnt;
vector<AC> v;
bool cmp(AC a,AC b)
{
    return a.r<b.r;
}
ll upper__bound(ll l,ll r,AC k)
{
    ll pos=-1;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if (v[mid].r>k.r)
        {
            pos=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return pos;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for (ll i=1;i<=n;i++)
    {
        cin>>x;
        v.push_back((AC){i,x,0});
    }
    sort(v.begin(),v.end(),cmp);
    while (ans!=v.size())
    {
        ll pos=upper__bound(0LL,(ll)v.size()-1,v[l]);
        if (pos!=-1)
        {
            v[pos].vis=1;
            ans++;
            if (v[l].vis)
                ans--;
            v.erase(v.begin()+l);
        }
        else
        {
            v[l].vis=1;
            v[l+1].vis=1;
            ans++;
            l+=2;
        }
    }
    cout<<ans;
    return 0;
}
