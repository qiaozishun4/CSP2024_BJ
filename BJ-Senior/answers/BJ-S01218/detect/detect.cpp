#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int L[MAXN],R[MAXN],N,n,a[MAXN],v[MAXN],d[MAXN],p[MAXN],m,V,T,ans;
struct node
{
	int l,r;
	bool operator<(const node &o) const
	{
		return l<o.l;
	}
}t[MAXN];
inline int read()
{
	int p=1,q=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') p=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		q=(q<<1)+(q<<3)+(ch^48),ch=getchar();
	return p*q;
}
void solve2(int d,int v,int a)
{
	if(d>p[m]) return;
	if(a==0)
	{
		if(v<=V) return;
		R[++N]=m,ans++;
		int l=1,r=m;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(p[mid]>=d) L[N]=mid,r=mid-1;
			else l=mid+1;
		}
		return;
	}
	if(a>0)
	{
		int l=1,r=m,find=m+1;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(p[mid]>=d&&V*V-v*v<2*a*(p[mid]-d)) find=mid,r=mid-1;
			else l=mid+1;
		}
		if(find==m+1) return;
		L[++N]=find,R[N]=m,ans++;
		return;
	}
	int l=1,r=m,findl;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(p[mid]>=d) findl=mid,r=mid-1;
		else l=mid+1;
	}
	if(V*V-v*v>=2*a*(p[findl]-d)) return;
	ans++,L[++N]=findl;
	l=L[N],r=m;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(V*V-v*v<2*a*(p[mid]-d)) R[N]=mid,l=mid+1;
		else r=mid-1;
	}
}
void solve()
{
	n=read(),m=read(),V=read(),V=read();
	for(int i=1;i<=n;i++)
		d[i]=read(),v[i]=read(),a[i]=read();
	for(int i=1;i<=m;i++) p[i]=read();
	N=ans=0;
	for(int i=1;i<=n;i++) solve2(d[i],v[i],a[i]);
	cout<<ans<<' ';
	ans=m;
	for(int i=1;i<=N;i++) t[i].l=L[i],t[i].r=R[i];
	sort(t+1,t+N+1);
	int now=0;
	for(int i=1;i<=N;i++)
	{
		if(t[i].l>now) now=t[i].r,ans--;
		else now=min(now,t[i].r);
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	T=read();
	while(T--) solve();
	return 0;
}