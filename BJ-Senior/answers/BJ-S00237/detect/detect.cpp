#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,L,p[N],ans1,ans2;
double V;
struct Car{int d,v,a;}c[N];
inline void work()
{
	ans1=ans2=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (p[j]<c[i].d) continue;
			double vnow=sqrt(c[i].v*c[i].v*1.0+2.0*c[i].a*double(p[j]-c[i].d));
			if (vnow>V){ans1++;break;}
		}
	}
	int mx=(1<<m)-1,cnt;
	for (int sta=0;sta<=mx;sta++)
	{
		cnt=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<m;j++)
			{
				if (p[j+1]<c[i].d||(!((sta>>j)&1))) continue;
				double vnow=sqrt(c[i].v*c[i].v*1.0+2.0*c[i].a*double(p[j+1]-c[i].d));
				if (vnow>V){cnt++;break;}
			}
		}
		if (cnt==ans1)
		{
			cnt=0;
			for (int i=0;i<m;i++)
				if (!((sta>>i)&1)) cnt++;
			ans2=max(ans2,cnt);
		}
	}
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n>>m>>L>>V;
		bool flgA=1,flgB=1,flgC=1;
		for (int i=1;i<=n;i++)
		{
			cin>>c[i].d>>c[i].v>>c[i].a;
			if (c[i].a!=0) flgA=0;
			if (c[i].a<=0) flgB=0;
			if (c[i].a>=0) flgC=0;
		}
		for (int i=1;i<=m;i++) cin>>p[i];
		if (n<=20&&m<=20)
		{
			work();
			cout<<ans1<<" "<<ans2<<"\n";
		}
		else if (flgA)
		{
			ans1=ans2=0;
			for (int i=1;i<=n;i++)
				if (1.0*c[i].v>V&&c[i].d<=p[m]) ans1++;
			if (ans1) ans2=m-1;
			else ans2=m;
			cout<<ans1<<" "<<ans2<<"\n";
		}
		else if (flgB)
		{
			ans1=ans2=0;
			for (int i=1;i<=n;i++)
			{
				if (c[i].d>p[m]) continue;
				double vnow=sqrt(c[i].v*c[i].v*1.0+2.0*c[i].a*double(p[m]-c[i].d));
				if (vnow>V) ans1++;
			}
			if (ans1) ans2=m-1;
			else ans2=m;
			cout<<ans1<<" "<<ans2<<"\n";
		}
		/*
		else if (flgC)
		{
			
		}*/
	}
	return 0;
}