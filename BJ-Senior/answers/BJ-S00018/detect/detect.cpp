#include<bits/stdc++.h>
using namespace std;
double a[100005];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,m,l,k;
		double mv=INT_MAX,ml=INT_MAX,xm=0,ans=0;
		cin>>n>>m>>l>>k;
		for(int i=1;i<=n;i++)
		{
			double d,v;
			cin>>d>>v>>a[i];
			a[i]=sqrt((v*v+2*a[i]*(l-d)));
			mv=min(mv,v);
			ml=min(ml,a[i]);
		}
		for(int i=1;i<=m;i++)
		{
			double x;
			cin>>x;
			xm=max(xm,x);
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=xm)
				ans++;
		}
		cout<<ans<<" ";
		if(xm<ml&&mv>=0)
			cout<<m<<endl;
		else
			cout<<m-1<<endl;
	}
	return 0;
}