#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,l,V;
int ans1,ans2;
int d[100005];
int v[100005];
int a[100005];
int p[100005];
struct node
{
	int l,r;
}b[100005];
bool cmp(node aa,node bb)
{
	if(aa.l==bb.l) return aa.r<bb.r;
	return aa.l<bb.l;
}
void work(int x)
{
	int ll=1,rr=m;
	while(ll<=rr)
	{
		int mid=(ll+rr)>>1,y=p[mid];
		if(y<d[x])
		{
			ll=mid+1;
			continue;
		}
		double vnow=sqrt(2*a[x]*(y-d[x])+v[x]*v[x]);
		if(vnow>V) b[x].l=mid,rr=mid-1;
		else ll=mid+1;
	}
	if(b[x].l) b[x].r=m;
	return;
}
void work1(int x)
{
	int ll=1,rr=m;
	while(ll<=rr)
	{
		int mid=(ll+rr)>>1,y=p[mid];
		if(y<d[x])
		{
			ll=mid+1;
			continue;
		}
		if(v[x]*v[x]+(y-d[x])*2*a[x]<=V*V)
		{
			rr=mid-1;
		}
		else b[x].r=mid,ll=mid+1;
	}
	ll=1,rr=b[x].r;
	while(ll<=rr)
	{
		int mid=(ll+rr)>>1,y=p[mid];
		if(y<d[x])
		{
			ll=mid+1;
			continue;
		}
		if(mid<=b[x].r) b[x].l=mid,rr=mid-1;
		else ll=mid+1;
	}
}
signed main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--)
	{
		memset(b,0,sizeof(b));
		ans1=ans2=0;
		cin>>n>>m>>l>>V;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++) cin>>p[i];
		sort(p+1,p+m+1);
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				if(v[i]<=V) continue;
				work(i);
			}
			if(a[i]>0)
			{
				work(i);
			}
			if(a[i]<0)
			{
				work1(i);
			}
			// cout<<b[i].l<<' '<<b[i].r<<endl;
		}
		for(int i=1;i<=n;i++)
		{
			if(b[i].r) ans1++;
		}
		sort(b+1,b+n+1,cmp);
		// for(int i=1;i<=n;i++) cout<<b[i].l<<' '<<b[i].r<<endl;
		int nl=0,nr=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i].r==0) continue;
			if(nl==0) nl=b[i].l,nr=b[i].r;
			if(b[i].l>nr) ans2++,nl=b[i].l,nr=b[i].r;
			nr=min(nr,b[i].r);
		}
		if(nr) ans2++;
		cout<<ans1<<' '<<m-ans2<<endl;
	}
}