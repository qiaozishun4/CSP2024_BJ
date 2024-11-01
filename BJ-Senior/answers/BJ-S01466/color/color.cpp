#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
bool book[N];
int c[N];
ll a[N];
ll ans;
int n;
void dfs(int l)
{
	if(l==n+1)
	{
		int p1=0,p2=0;
		ll res=0;
		for(int i=1;i<=n;i++)
		{
			if(book[i]==0)
			{
				if(p1&&a[p1]==a[i]) res+=a[i];
				p1=i;
			}
			else
			{
				if(p2&&a[p2]==a[i]) res+=a[i];
				p2=i;
			}
		}
		ans=max(ans,res);
		return;
	}
	dfs(l+1);
	book[l]=1;
	dfs(l+1);
	book[l]=0;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		int maxn=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			c[a[i]]++;
			maxn=max(maxn,c[a[i]]);
		}
		if(maxn==1) 
		{
			cout<<0<<"\n";
			continue;
		}
		if(n<=15)
		{
			ans=0;
			dfs(1);
			cout<<ans<<'\n';
			continue;
		}
	}
	return 0;
}
