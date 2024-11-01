#include<bits/stdc++.h>
using namespace std;
long long d[100005],v[100005],a[100005],p[100005];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,m,l,v2;
		cin>>n>>m>>l>>v2;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
		}
		long long maxx=0;
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
			maxx=max(maxx,p[i]);
		}
		for(int i=1;i<=n;i++)
		{
			if(v[i]>v2&&d[i]<=maxx)
			{
				ans++;
			}
		}
		cout<<ans<<' '<<m-1<<'\n';
	}
	return 0;
}
