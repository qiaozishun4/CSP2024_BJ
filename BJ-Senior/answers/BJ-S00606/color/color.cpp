#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,M=1e6+5;
ll a[N],dp[N],sumdp[N];
int lst[M];
struct Node{
	int l,r,ln,rn;
	ll v;
}tree[4*N];
void Build(int l,int r,int p)
{
	tree[p].l=l;tree[p].r=r;
	if(l==r)
	{
		tree[p].v=0;
		tree[p].ln=tree[p].rn=a[l];
		return;
	}
	int mid=(l+r>>1);
	Build(l,mid,(p<<1));
	Build(mid+1,r,(p<<1|1));
	tree[p].ln=tree[p<<1].ln;
	tree[p].rn=tree[p<<1|1].rn;
	tree[p].v=tree[p<<1].v+tree[p<<1|1].v;
	if(tree[p<<1].rn==tree[p<<1|1].ln)
		tree[p].v+=tree[p<<1].rn;
}
ll Solve(int l,int r,int p)
{
	if(l>r)
		return 0;
	if(l<=tree[p].l&&tree[p].r<=r)
		return tree[p].v;
	int mid=(tree[p].l+tree[p].r>>1);
	if(l<=mid&&mid<r)
	{
		if(tree[p<<1].rn==tree[p<<1|1].ln)
			return Solve(l,r,p<<1)+Solve(l,r,p<<1|1)+tree[p<<1].rn;
		else
			return Solve(l,r,p<<1)+Solve(l,r,p<<1|1);
	}
	else if(l<=mid)
		return Solve(l,r,p<<1);
	else
		return Solve(l,r,p<<1|1);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<=n;i++)
			dp[i]=sumdp[i]=0;
		for(int i=0;i<=1e6;i++)
			lst[i]=0;
		ll sum;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		Build(1,n,1);
		for(int i=1;i<=n;i++)
		{
			if(lst[a[i]]==0)
			{
				lst[a[i]]=i;
				sumdp[i]=sumdp[i-1];
				continue;
			}
			sum=Solve(lst[a[i]]+1,i-1,1);
			if(lst[a[i]]+1==i)
				dp[i]=a[i]+sumdp[lst[a[i]]]+sum;
			else
				dp[i]=a[i]+sumdp[lst[a[i]]+1]+sum;
			lst[a[i]]=i;
			sumdp[i]=max(sumdp[i-1],dp[i]);
		}
		cout<<sumdp[n]<<'\n';
	}
	return 0;
}