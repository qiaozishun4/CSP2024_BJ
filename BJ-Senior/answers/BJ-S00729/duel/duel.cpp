#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int n;
int r,cnt[maxn],maxr=-1;

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>r;
		maxr=max(maxr,r);
		cnt[r]++;
	}
	long long rst=0,ans=n;
	for (int i=2;i<=maxr;i++)
	{
		rst+=cnt[i-1];
		if (cnt[i]>=rst)
		{
			ans-=rst;
			rst=0;
		}
		else if (cnt[i]<rst)
		{
			ans-=cnt[i];
			rst-=cnt[i];
		}
	}
	cout<<ans;
	return 0;
}
