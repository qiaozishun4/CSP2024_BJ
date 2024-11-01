#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int r[100005];
int ans;
int cnt;
int h[100005];
int c[100005];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ans=n;
	for (int i=1;i<=n;i++)
	{
		cin>>r[i];
		h[r[i]]++;
	}
	sort(r+1,r+n+1);
	for (int i=1;i<=n;i++)
	{
		if (r[i]>r[i-1])
		{
			c[i]=c[i-1]+h[r[i-1]];
		}
		else
		{
			c[i]=c[i-1];
		}
	}
	
	for (int i=1;i<=n;i++)
	{
		if (c[i]-cnt>0)
		{
			cnt++;
			ans--;
		}
	}
	cout<<ans;
	return 0;
}
