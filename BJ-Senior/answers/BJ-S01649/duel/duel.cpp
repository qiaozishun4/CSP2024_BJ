#include<bits/stdc++.h>
using namespace std;
int n,a[100005],l,r,ans;
bool vis[100005];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	l=1,r=2;
	while(l<r&&r<=n)
	{
		if(a[r]>a[l])
		{
			vis[l]=1;
			l++,r++;
		}
		else r++;
	}
	for(int i=1;i<=n;i++) if(vis[i]) ans++;
	printf("%d",n-ans);
	return 0;
}