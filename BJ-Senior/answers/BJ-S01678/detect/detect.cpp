#include <bits/stdc++.h>
using namespace std;
int d[101000],a[100100],v[100100],p[100100];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t,n,m,l,s,ans1=0,ans2=0;
	scanf("%d",&t);
	for (int i = 1; i <= t; i++)
	{
		scanf("%d%d%d%d",&n,&m,&l,&s);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
		}
		for (int i = 1; i <= m; i++)
		{
			scanf("%d",&p[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if(p[j]>=d[i]&&sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]))>s)
				{
					ans1++;
					break;
				}

			}	
		}
		printf("%d %d",ans1,m-2);
	}
	

	return 0;
}