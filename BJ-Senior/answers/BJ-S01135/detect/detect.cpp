#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=1e6+5;
int t;
int n,m;
double l,V;
double d[N],v[N],a[N];
double p[M];
bool flag1[N];
bool flag2[N];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(flag1,0,sizeof(flag1));
		memset(flag2,0,sizeof(flag2));
		int ans1=0,ans2=0;
		scanf("%d%d%lf%lf",&n,&m,&l,&V);
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf%lf",&d[i],&v[i],&a[i]);
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%lf",&p[i]);
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				double val=sqrt(v[j]*v[j]+2*a[j]*p[i]);
				if(val>V)
				{
					flag1[j]=1;
					flag2[i]=1;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(flag1[i])
			{
				ans1++;
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(flag2[i]==0)
			{
				ans2++;
			}
		}
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}