#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t[100005],r,ans,maxn;
signed main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&r);
		t[r]++;
		maxn=max(maxn,r);
	}
	for(int i=maxn;i;--i)
	{
		ans=max(ans,t[i]);
	}
	cout<<ans;
	return 0;
}