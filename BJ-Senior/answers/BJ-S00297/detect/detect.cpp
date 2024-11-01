#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read()
{
	int res=0,op=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		op|=ch=='-';
		ch=getchar();
	}
	while(isdigit(ch))
	{
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	return op?-res:res;
}
inline void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}
int t,n,m,L,V,d[100005],v[100005],a[100005],p[100005],cnt,ans;
struct node
{
	int l,r;
	bool operator <(const node &x) const
	{
		return r<x.r;
	}
}b[100005];
void insert(int x,int y)
{
	int l=1,r=m+1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(p[mid]<x) l=mid+1;
		else r=mid;
	}
	node tp;
	tp.l=l;
	l=0;
	r=m;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(p[mid]>y) r=mid-1;
		else l=mid;
	}
	tp.r=l;
	if(tp.l<=tp.r)
	{
		++ans;
		b[++cnt]=tp;
	}
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	t=read();
	while(t--)
	{
		cnt=ans=0;
		n=read();
		m=read();
		L=read();
		V=read();
		for(int i=1;i<=n;++i)
		{
			d[i]=read();
			v[i]=read();
			a[i]=read();
		}
		for(int i=1;i<=m;++i) p[i]=read();
		for(int i=1;i<=n;++i)
		{
			if(v[i]>V)
			{
				if(a[i]>=0) insert(d[i],L);
				else insert(d[i],d[i]+((v[i]+V)*(v[i]-V)-1)/(-2*a[i]));
			}
			else if(a[i]>0)
			{
				int l=d[i]+(v[i]+V)*(V-v[i])/(2*a[i])+1;
				if(l<=L) insert(l,L);
			}
		}
		sort(b+1,b+1+cnt);
		int sum=m,r=0;
		for(int i=1;i<=cnt;++i)
		{
			if(b[i].l>r)
			{
				--sum;
				r=b[i].r;
			}
		}
		write(ans);
		putchar(' ');
		write(sum);
		puts("");
	}
	return 0;
}