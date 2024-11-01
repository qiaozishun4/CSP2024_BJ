#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=1e6+10;
int a[N],d[N],v[N],p[N];
struct node
{
	int l,r;
}c[N];
int n,m,len,lim;
double eps=1e-6;
int er(double x)
{
	int l=1,r=m,res=-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(double(p[mid])-x>eps) r=mid-1,res=mid;
		else l=mid+1;
	}
	return res;
}
bool cmp(node q,node w){return q.l>w.l;}
void init()
{
	for(int i=1;i<=n;i++)
		c[i].l=c[i].r=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0) 
		{
			if(v[i]>lim)
			{
				int x=er(double(d[i]-(1e-5)));
				if(x!=-1) c[i].l=x,c[i].r=m;
			}
		}
		else if(a[i]>0)
		{
			if(v[i]>lim)
			{
				int x=er(double(d[i]-(1e-5)));
				if(x!=-1) c[i].l=x,c[i].r=m;
			}
			else
			{
				double t=double(lim*lim-v[i]*v[i])/double(2.0*double(a[i]));
				t=t+double(d[i]);
				int x=er(t);
				if(x!=-1) c[i].l=x,c[i].r=m;
			}
		}
		else
		{
			if(v[i]>lim)
			{
				double t=double(lim*lim-v[i]*v[i])/double(2.0*double(a[i]));
				t=t+double(d[i]);
				int x=er(t-(1e-5)),y=er(double(d[i]-(1e-5)));
				if(y!=-1&&x!=y) 
				{
					if(x==-1) c[i].l=y,c[i].r=m;
					else c[i].l=y,c[i].r=x-1;
				}
			}
		}
	}
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>len>>lim;
		for(int i=1;i<=n;i++)
			cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++)
			cin>>p[i];
		init();
		int res=0,ans=0;
		for(int i=1;i<=n;i++)
			if(c[i].l) res++;
		cout<<res<<" ";
		sort(c+1,c+1+n,cmp);
		int last=1e7;
		for(int i=1;i<=n;i++)
		{
			if(c[i].l==0) continue;
			if(c[i].r>=last) continue;
			ans++;
			last=c[i].l;
		}
		cout<<m-ans<<'\n';
	}
	return 0;
}
