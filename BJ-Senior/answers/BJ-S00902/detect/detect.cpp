#include <bits/stdc++.h>
using namespace std;
struct node
{
	int b,e;
}car[100005];
bool cmp(node x,node y)
{
	return x.e!=y.e?x.e<y.e:x.b<y.b;
}
int d[100005],v[100005],a[100005],p[100005];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while (T--)
	{
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		for (int i=1;i<=n;i++)
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
		for (int i=1;i<=m;i++)
			scanf("%d",&p[i]);
		p[m+1]=1e9;
		int cnt=0;
		for (int i=1;i<=n;i++)
		{
			double l=m+1,r=0;
			if (a[i]<=0)
			{
				if (v[i]>V)
				{
					l=lower_bound(p+1,p+m+2,d[i])-p;
					if (a[i]==0)
						r=m;
					else
					{
						double t=(double)(V-v[i])/a[i];
						double len=(d[i]+max(v[i]*t+a[i]*t*t/2,(double)0));
						r=lower_bound(p+1,p+m+2,len/*+(len!=int(len))*/)-p-1;
					}
				}
			}
			else
			{
				double t=(double)(V-v[i])/a[i];
				if (v[i]>=V)
					l=lower_bound(p+1,p+m+2,d[i])-p;
				else
				{
					double len=d[i]+max(v[i]*t+a[i]*t*t/2,(double)0);
					l=upper_bound(p+1,p+m+2,(int)len)-p;
				}
				if (sqrt(v[i]*v[i]+2*a[i]*(p[m]-d[i]))>V)
					r=m;
			}
//			cout<<l<<" "<<r<<"\n";
			if (l<=r&&r>=1&&l<=m)
			{
				cnt++;
				car[cnt].b=l;
				car[cnt].e=r;
			}
		}
		sort(car+1,car+cnt+1,cmp);
		int ans=0,now=0;
		for (int i=1;i<=cnt;i++)
		{
//			cout<<car[i].b<<" "<<car[i].e<<"\n";
			if (car[i].b>now)
			{
				ans++;
				now=car[i].e;
//				cout<<i<<"\n";
			}
		}
		cout<<cnt<<" "<<m-ans<<"\n";
	}
	return 0;
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15
*/
