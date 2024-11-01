#include<bits/stdc++.h>
using namespace std;
const int MAXN=4e5+5;
int n,A[MAXN],k,C[MAXN],N,p[MAXN],a[MAXN],x[4],t,lst[MAXN],m,L[MAXN],R[MAXN],id[20][MAXN],mp[MAXN],ll[MAXN],rr[MAXN],f[MAXN],g[MAXN],book[MAXN],c[MAXN],book2[MAXN];
long long ans[MAXN];
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
inline int qmin(int x,int y)
{
	return (x<y?x:y);
}
inline int qmax(int x,int y)
{
	return (x>y?x:y);
}
void solve2(int n)
{
	for(int i=1;i<n*2;i++) book[i]=n,book2[i]=0;
	// cout<<n<<endl;
	for(int i=n;i<n*2;i++) f[i]=a[i-n+1],g[i]=i-n,ll[i]=i-n+1;
	for(int i=n-1;i>0;i--)
	{
		int M=mp[n]-mp[i];
		ll[i]=ll[i<<1];
		// cout<<n<<' '<<i<<' '<<M<<' '<<mp[n]<<' '<<mp[i]<<endl;
		int ls=(i<<1),rs=(i<<1)+1,o=c[id[M][ll[i]]];
		if(o)
		{
			f[i]=(f[rs]>=M?f[rs]:f[ls]),g[i]=g[rs];
			if(f[rs]>=M) book[ls]=g[rs];
			book2[rs]=M;
		}
		else
		{
			f[i]=(f[ls]>=M?f[ls]:f[rs]),g[i]=(f[ls]>=M?g[ls]:g[rs]);
			if(f[ls]>=M) book[rs]=g[ls];
			book2[ls]=M;
		}
		// cout<<i<<' '<<ll[i]<<' '<<rr[i]<<' '<<f[i]<<' '<<g[i]<<' '<<o<<' '<<mp[rr[i]-ll[i]+1]<<endl;
	}
	for(int i=2;i<(n<<1);i++)
	{
		book[i]=qmin(book[i],book[i>>1]),book2[i]=qmax(book2[i],book2[i>>1]);
		if(i>=n)
		{
			int tmp=book[i];
			if(a[i-n+1]<book2[i]) tmp=min(tmp,i-n);
			if(tmp>(n>>1)) ans[tmp]+=i-n+1;
			// cout<<i<<" "<<ll[i]<<" "<<rr[i]<<' '<<tmp<<' '<<book[i]<<' '<<book2[i]<<' '<<a[i-n+1]<<' '<<n<<endl;
		}
	}
	for(int i=n-1;i>(n>>1);i--) ans[i]+=ans[i+1];
}
void solve()
{
	// cout<<N<<endl;
	// for(int i=1;i<=N;i++) cout<<a[i]<<' ';cout<<endl;
	memset(ans,0,sizeof(ans));
	ans[1]=1;
	for(int i=2;i<=N;i*=2) solve2(i);
	// for(int i=1;i<=N;i++) cout<<ans[i]<<' ';cout<<endl;
	long long as=0;
	for(int i=1;i<=m;i++) as^=1ll*i*ans[C[i]];
	cout<<as<<endl;
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>A[i];
	for(int i=1;i<=m;i++) cin>>C[i];
	N=1;
	while(N<n) N*=2,k++;
	for(int i=1;i<=N;i++) mp[i]=mp[i>>1]+1;	
	for(int len=N/2,i=1,p=1;len>0;len/=2,p++)
	{
		int l=1,r=N/len;
		for(int j=1;j<=len;j++,i++)
		{
			id[p][l]=i;
			char ch;
			cin>>ch;
			c[i]=ch-'0',L[i]=l,R[i]=r;
			l+=N/len,r+=N/len;
		}
	}
	cin>>t;
	while(t--)
	{
		for(int i=0;i<4;i++) cin>>x[i];
		for(int i=1;i<=N;i++) a[i]=min((A[i]^x[i%4]),20);
		solve();
	}
	return 0;
}