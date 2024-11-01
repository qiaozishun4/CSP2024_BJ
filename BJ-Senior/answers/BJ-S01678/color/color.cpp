#include <bits/stdc++.h>
using namespace std;
int a[101000];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t,n,ans=0;
	scanf("%d",&t);
	for (int i = 1; i <= t; i++)
	{
		scanf("%d",&n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d",&a[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = i+1; j <= n; j++)
			{
				if(a[i]==a[j]&&i!=j)
				{
					ans+=a[j];
				}
			}
		}
		printf("%d\n",ans);
		ans=0;

	}
	

	return 0;
}