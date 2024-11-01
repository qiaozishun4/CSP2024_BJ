#include <iostream>
using namespace std;
int a[100002],h[100002];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,mx=0;
	cin>>n;
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		h[a[i]]++;
		mx=max(mx,a[i]);
	}
	for (int i=1;i<=mx;i++)
	{
		int mn=min(ans,h[i]);
		ans=ans-mn+h[i];
	}
	cout<<ans;
	return 0;
}