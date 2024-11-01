#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int d[N],v[N],p[N],vis[N];
double a[N];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,l,vn;
		cin>>n>>m>>l>>vn;
		bool s0=true,e0=true,b0=true;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]<0)
			{
				e0=false;
				b0=false;
			}
			else if(a[i]==0)
			{
				s0=false;
				b0=false;
			}
			else
			{
				s0=false;
				e0=false;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
		}
		sort(p+1,p+m+1);
		if(e0==true)
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(v[i]>vn&&d[i]<=p[m])
				{
					cnt++;
				}
			}
			if(cnt==0)
			{
				cout<<cnt<<" "<<m<<endl;
			}
			else
			{
				cout<<cnt<<" "<<m-1<<endl;
			}
		}
		else if(b0==true)
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				double s=p[m]-d[i];
				double vs=v[i]*v[i]+2*a[i]*s;
				//double vs=v[i]+a[i]*(p[m]-d[i]);
				if(vs>vn*vn&&d[i]<=p[m])
				{
					cnt++;
				}
			}
			if(cnt==0)
			{
				cout<<cnt<<" "<<m<<endl;
			}
			else
			{
				cout<<cnt<<" "<<m-1<<endl;
			}
		}
	}
	return 0;
}