#include<bits/stdc++.h>

using namespace std;

int n,m;
int k;
int _a[100005];
int a[100005];
int c[100005];
char d[20][100005];
int win[100005];
int t;

int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&_a[i]);
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&c[i]);
	}
	for (int i=0;i<=20;i++)
	{
		if ((1<<i)>=n) 
		{
			k=i;
			break;
		}
	}
	for (int i=1;i<=k;i++)
	{
		scanf("%s",d[i]+1);
	}
	scanf("%d",&t);
	while (t--)
	{
		int x[4];
		scanf("%d%d%d%d",&x[0],&x[1],&x[2],&x[3]);
		for (int i=1;i<=n;i++)
		{
			a[i]=_a[i]^x[i%4];
		}
		//n,m
		//a
		//c
		//d
		int ans=0;
		for (int i=1;i<=m;i++) //知道了前c[i]个人的信息
		{
			for (int j=1;j<=c[i];j++) win[j]=j;
			for (int j=1;(1<<j)<c[i];j++)
			{
				for (int k=1,l=1;l<=c[i];k++,l+=(1<<j))
				{
					if (d[j][k]=='1') //big
					{
						if (a[win[l+(1<<(j-1))]]>=j)
						{
							win[l]=win[l+(1<<(j-1))];
						}
					}
					else
					{
						if (a[win[l]]<j)
						{
							win[l]=win[l+(1<<(j-1))];
						}
					}
				}
				// printf("%d\n",win[1]);
			}
			ans^=win[1]*i;
		}
		printf("%d\n",ans);
	}
	return 0;
}