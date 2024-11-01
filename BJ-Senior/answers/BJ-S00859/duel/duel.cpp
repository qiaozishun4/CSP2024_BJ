#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n,r[N],cnt[N],sum,ans[N],x;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	sum=n;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&r[i]);
		cnt[r[i]]++;
	}

	sort(r,r+n);
	for (int i=0;i<n;i++)
	{
		if (r[i]!=ans[x])
		{
			ans[++x]=r[i];
		}
	}
	for (int i=2;i<=x;i++){
		sum-=min(cnt[ans[i]],cnt[ans[i-1]]);
	}
	cout<<sum;
	return 0;
}
