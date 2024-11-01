#include<bits/stdc++.h>

using namespace std;

int n;
int a[100005];
int b[100005];
int nxt[100005];
int ans;

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		b[a[i]]++;
	}
	int last=0;
	for (int i=1;i<=100000;i++)
	{
		if (b[i])
		{
			nxt[last]=i;
			last=i;
			// printf("b[%d]=%d\n",i,b[i]);
		}
	}
	nxt[last]=100001;
	last=nxt[0];
	for (int i=nxt[0];i<=100000;i=nxt[i])
	{
		while (b[i]>=b[last]&&last<i)
		{
			last=nxt[last];
		}
		if (last<i)
		{
			b[last]-=b[i];
		}
	// printf("b[last]=b[%d]=%d\n",last,b[last]);
	}
	ans=0;
	while (last<=100000)
	{
		ans+=b[last];
		last=nxt[last];
		// printf("b[%d]=%d\n",last,b[last]);
	}
	printf("%d",ans);
	return 0;
	
}