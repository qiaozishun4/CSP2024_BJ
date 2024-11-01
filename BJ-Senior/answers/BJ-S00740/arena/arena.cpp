#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,k=-1,k1=1,ans;
int a1[100005];
int a[100005];
int c[100005];
int b[4];
string s[35];
int work(int l,int r,int x)
{

	int mid=(l+r)>>1;
	int p1,p2;
	if(l+1!=r) p1=work(l,mid,x-1),p2=work(mid+1,r,x-1);
	else p1=l,p2=r;	
	// cout<<l<<' '<<r<<' '<<x<<' '<<p1<<' '<<p2<<endl;
	if(s[x][l/(1ll<<x)]=='0')
	{
		if(a[p1]>=x) return p1;
		return p2;
	}
	if(a[p2]>=x) return p2;
	return p1;
}
signed main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a1[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	while(k1<=n) k++,k1*=2;
	for(int i=1;i<=k;i++) cin>>s[i];
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>b[0]>>b[1]>>b[2]>>b[3];
		for(int i=1;i<=n;i++)
		{
			a[i]=a1[i]^(b[i%4]);
		}
		for(int i=1;i<=m;i++)
		{
			int t1=-1,t2=1;
			while(t2<=c[i]) t1++,t2*=2;
			if(t1==0)
			{
				ans^=i;
				continue;
			}
			ans^=(i*work(1,c[i],t1));
		}
		cout<<ans<<endl;
	}
}
/*
4 3
0 0 0 0
1 2 4
10
1
1
2 1 0 0
*/