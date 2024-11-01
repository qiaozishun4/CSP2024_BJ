#include <bits/stdc++.h>
using namespace std;
int a[101000];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,c,ans,k,p=1;
	scanf("%d",&n);
	ans=n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d",&a[i]);
		
		
	}
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++)
	{
		k=a[p];
		if(a[i]>a[p])
		{
			p++;
			ans--;
		}
	}
	printf("%d",ans);

	return 0;
}