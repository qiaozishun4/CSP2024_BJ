#include <bits/stdc++.h>
using namespace std;
int r[100005],cnt[100005];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>r[i];
	sort(r+1,r+n+1);
	int ans=n,dif=0;
	for (int i=1;i<=n;i++)
	{
		if (r[i]!=r[i-1])
			dif++;
		cnt[dif]++;
	}
	int now=0;
	for (int i=1;i<=dif;i++)
	{
		ans-=min(cnt[i],now);
		now-=min(now,cnt[i]);
		now+=cnt[i];
	}
	cout<<ans<<"\n";
	return 0;
}
