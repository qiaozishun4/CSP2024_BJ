#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],c[N],ans;
inline int calc1()
{
	int lst[2]={-1,-1},res=0;
	for (int i=1;i<=n;i++)
	{
		if (lst[c[a[i]]]==-1) {lst[c[a[i]]]=i;continue;}
		else if (a[lst[c[a[i]]]]==a[i]) res+=a[i];
		lst[c[a[i]]]=i;
	}
	return res;
}
inline void work1()
{
	int mx=(1<<10)-1;
	ans=0;
	for (int sta=0;sta<=mx;sta++)
	{
		for (int i=0;i<10;i++) c[i+1]=((sta>>i)&1);
		ans=max(ans,calc1());
	}
}
inline int calc2()
{
	int lst[2]={-1,-1},res=0;
	for (int i=1;i<=n;i++)
	{
		if (lst[c[i]]==-1) {lst[c[i]]=i;continue;}
		else if (a[lst[c[i]]]==a[i]) res+=a[i];
		lst[c[i]]=i;
	}
	return res;
}
inline void work2()
{
	int mx=(1<<n)-1;
	ans=0;
	for (int sta=0;sta<=mx;sta++)
	{
		for (int i=0;i<n;i++) c[i+1]=((sta>>i)&1);
		ans=max(ans,calc2());
	}
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		if (n<=15)
		{
			work2();
			cout<<ans<<"\n";
		}
		else
		{
			work1();
			cout<<ans<<"\n";
		}
	}
	return 0;
}