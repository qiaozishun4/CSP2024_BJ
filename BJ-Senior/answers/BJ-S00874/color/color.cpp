#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll a[N];
ll n,cnt;
ll col[N];
ll ret=0;
void dfs(ll c)
{
	if(c>n)
	{
		ll ans=0;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<i;j++)
				if(col[j]==col[i] && a[j]==a[i])
					ans+=a[i];
		}
		/*
		for(ll i=1;i<=n;i++)
			cout<<col[i]<<" ";
		cout<<endl;
		cout<<"ans="<<ans<<endl;
		*/
		ret=max(ret,ans);
		return;
	}
	col[c]=1;
	dfs(c+1);
	col[c]=2;
	dfs(c+1);
}
int main()
{
    ios::sync_with_stdio(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ll T;
    cin>>T;
    while(T--)
    {
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ret=0;
    dfs(1);
    cout<<ret<<endl;
}
    return 0;
}
