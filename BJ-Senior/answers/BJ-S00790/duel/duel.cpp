#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,a[100005],b[100005],maxn=-1,minn=1e5+1,now,ans=0;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        if(maxn<a[i])maxn=a[i];
        if(minn>a[i])minn=a[i];
        b[a[i]]++;
    }
    ans=b[minn];
    for(ll i=minn+1;i<=maxn;i++)
    {
        if(b[i]!=0)ans=max(b[i],ans);
    }
    cout<<ans;
    return 0;
}
