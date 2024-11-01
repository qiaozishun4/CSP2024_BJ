#include<bits/stdc++.h>
#define N 10000007
using namespace std;
long long p[N];
long long d[N],v[N],a[N];
long long pm=-1;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	long long n,m,l,v0,ans=0,v1;
	for(int k=1;k<=t;k++)
	{
		cin>>n>>m>>l>>v0;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++)
			{
				cin>>p[i];
				if(p[i]>pm && p[i]<=l)
					pm=p[i];
			}
		for(int i=1;i<=n;i++)
		{
			
			if(a[i]==0)
			{
				//for(int i=1;i<=n;i++)
				//{
					if(d[i]<=pm && v[i]>v0)
					ans++;
				//}
				//cout<<ans<<" "<<"1"<<endl;
			}
			if(a[i]>0)
			{
				//for(int i=1;i<=m;i++)
				//{
					//cin>>p[i];
					//if(p[i]>pm)
						//pm=p[i];
				//
				//}
				//for(int i=1;i<=n;i++)
				//{
					if(d[i]<=pm)
					{
						v1=(pm-d[i])*a[i]*2+(v[i]*v[i]);
						if(v0*v0<v1)
						ans++;
					}
				//}
			}
		}
		if(ans!=0)
		cout<<ans<<" "<<m-1<<endl;
		else
		cout<<ans<<" "<<m<<endl;
		ans=0;
		pm=-1;
	}
	return 0;
}
