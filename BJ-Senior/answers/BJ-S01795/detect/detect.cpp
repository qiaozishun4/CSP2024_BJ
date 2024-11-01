#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,m,l,v;
int d[N],vi[N],a[N],p[N];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int ans=0;
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>vi[i]>>a[i];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(vi[i]>v&&d[i]<=p[m]) ans++;
		}
		cout<<ans<<" ";
		if(ans!=0) cout<<m-1<<endl;
		else cout<<m<<endl;
	}
	return 0;
}