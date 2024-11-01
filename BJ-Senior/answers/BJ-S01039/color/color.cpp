#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll n,a[200001],c[200001],ans=0;
void dfs(ll x)
{
    if(x==n+1)
    {
        ll lst[3]={0,0,0},cnt=0;
        for(ll i=1;i<=n;i++)
        {
            if(lst[c[i]]==0 || a[lst[c[i]]]!=a[i]);
            else cnt+=a[i];
            lst[c[i]]=i;
        }
        ans=max(cnt,ans);
        return;
    }
    c[x]=1;
    dfs(x+1);
    c[x]=2;
    dfs(x+1);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll T;
    cin>>T;
    while(T--)
    {
        ans=0;
        cin>>n;
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        dfs(1);
        cout<<ans<<endl;
    }
    cout<<flush;
    return 0;
}
