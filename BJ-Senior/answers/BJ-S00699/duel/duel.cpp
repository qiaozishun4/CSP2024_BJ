#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t[100005],r[100005],ans,minn,maxn=-1,y;
signed main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	ans=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&r[i]);
		t[r[i]]++;
		maxn=max(r[i],maxn);
	}
	for(int i=1;i<=maxn;i++)
	{
		if(t[i]>0)
		{
			minn=i;
			break;
		}
	}
	for(int i=minn+1;i<=maxn;i++)
	{
		if(t[i]>0&&t[minn]>0&&t[i]>=t[minn])
		{
			ans-=t[minn];
			if(y>=t[i]-t[minn])
			{
				ans-=t[i]-t[minn];
				y-=t[i]-t[minn];
			}
			else ans-=y;
		}
		else if(t[i]>0&&t[minn]>0&&t[i]<t[minn])
		{
			ans-=t[i];
			y=y+t[minn]-t[i];
		}
		if(t[i]>0)minn=i;
	}
	printf("%lld",ans);
	return 0;
}