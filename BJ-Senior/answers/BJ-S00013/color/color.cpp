#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool b[200050];
ll n,a[200050],ans;
int f(int x)
{
	for(int i=x-1;i>=1;i--) if(b[i]==b[x]) return i;
	return 0;
}
void dfs(int cur)
{
	if(cur>n)
	{
		ll s=0;
		for(int i=1;i<=n;i++)
		{
			int fi=f(i);
			if(fi&&a[fi]==a[i]) s+=a[i];
		}
		ans=max(ans,s);
		return;
	}
	b[cur+1]=1;
	dfs(cur+1);
	b[cur+1]=0;
	dfs(cur+1);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		ans=LLONG_MIN;
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}
