#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e6+5;
int t,dp[MAXN],mx[MAXN],lst[MAXN],ans,a[MAXN],N,n,x;
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
void solve()
{
	memset(dp,0,sizeof(dp));
	memset(mx,0,sizeof(mx));
	memset(lst,0,sizeof(lst));
	ans=n=0;
	N=read();
	for(int i=1;i<=N;i++)
	{
		x=read();
		if(x==a[n]) ans+=x;
		else a[++n]=x;
	}
	for(int i=1;i<=n;i++)
	{
		if(!lst[a[i]])
		{
			mx[i]=mx[i-1],lst[a[i]]=i;
			continue;
		}
		dp[i]=max(mx[lst[a[i]]],dp[lst[a[i]]+1])+a[i];
		mx[i]=max(dp[i],mx[i-1]),lst[a[i]]=i;
	}
	cout<<mx[n]+ans<<endl;
}
signed main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	t=read();
	while(t--) solve();
	return 0;
}