#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int NR=1e5+5;
const double eps=1e-9;
int d[NR],v[NR],a[NR];
int p[NR];
struct Node
{
	int l,r;
	bool operator <(const Node &c)const
	{
		return r<c.r;
	}
}b[NR];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--)
	{
		int n,m,L,V;scanf("%d%d%d%d",&n,&m,&L,&V);
		int num=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d%d",d+i,v+i,a+i);
			if(a[i]==0)
			{
				if(v[i]<=V) continue;
				b[++num]=(Node){d[i],L};
			}
			if(a[i]>0)
			{
				int l=d[i],r=L;
				if(v[i]<=V)
				{
					l=(V*V-v[i]*v[i])/2/a[i]+d[i]+1;
					if(l>r) continue;
				}
				b[++num]=(Node){l,r};
			}
			if(a[i]<0)
			{
				int l=d[i],r=L;
				if(v[i]<=V) continue;
				int s=d[i]+floor(((double)V*V-v[i]*v[i])/2/a[i]-eps);
				if(s<L) r=s;
				b[++num]=(Node){l,r};
			}
		}
		for(int i=1;i<=m;++i)
			scanf("%d",p+i);
		//for(int i=1;i<=num;++i) printf("%d %d\n",b[i].l,b[i].r);
		sort(b+1,b+num+1);
		int ans1=0,ans2=0;
		int nw=0;
		bool flag=0;
		for(int i=1;i<=num;++i)
		{
			//printf("%d %d %d\n",b[i].l,b[i].r,nw);
			if(nw&&p[nw]>=b[i].l) {
				++ans1;
				continue;
			}
			int s=upper_bound(p+1,p+m+1,b[i].r)-p-1;
			if(s&&p[s]>=b[i].l)
			{
				nw=s;
				++ans1,++ans2;
			}
		}
		printf("%d %d\n",ans1,m-ans2);
	}
	return 0;
}