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
inline void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}
const ll inf=1e18;
map<int,int>f;
int t,n,m,a[200005],vl[200005];
ll tr[800005],lz[800005];
void build(int o,int l,int r)
{
	lz[o]=0;
	if(l==r)
	{
		tr[o]=l?-inf:0;
		return;
	}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	tr[o]=max(tr[o<<1],tr[o<<1|1]);
}
void add(int o,int l,int r,int x,ll k)
{
	if(l==r)
	{
		tr[o]=max(tr[o],k);
		return;
	}
	if(lz[o])
	{
		tr[o<<1]+=lz[o];
		lz[o<<1]+=lz[o];
		tr[o<<1|1]+=lz[o];
		lz[o<<1|1]+=lz[o];
		lz[o]=0;
	}
	int mid=(l+r)>>1;
	if(x<=mid) add(o<<1,l,mid,x,k);
	else add(o<<1|1,mid+1,r,x,k);
	tr[o]=max(tr[o<<1],tr[o<<1|1]);
}
ll query(int o,int l,int r,int x)
{
	if(l==r) return tr[o];
	if(lz[o])
	{
		tr[o<<1]+=lz[o];
		lz[o<<1]+=lz[o];
		tr[o<<1|1]+=lz[o];
		lz[o<<1|1]+=lz[o];
		lz[o]=0;
	}
	int mid=(l+r)>>1;
	if(x<=mid) return query(o<<1,l,mid,x);
	return query(o<<1|1,mid+1,r,x);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	t=read();
	while(t--)
	{
		vector<int>s;
		n=read();
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			s.push_back(a[i]);
		}
		sort(s.begin(),s.end());
		f.clear();
		m=0;
		for(int i=0;i<s.size();++i) if(!i||s[i]>s[i-1]) f[s[i]]=++m;
		for(int i=1;i<=n;++i)
		{
			vl[i]=a[i];
			a[i]=f[a[i]];
		}
		build(1,0,m);
		for(int i=2;i<=n;++i)
		{
			ll tmp=max(tr[1],query(1,0,m,a[i])+vl[i]);
			tr[1]+=a[i]==a[i-1]?vl[i]:0;
			lz[1]+=a[i]==a[i-1]?vl[i]:0;
			add(1,0,m,a[i-1],tmp);
		}
		write(tr[1]);
		puts("");
	}
	return 0;
}