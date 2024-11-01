#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int t,n,a[N];
stack<int> x,y;
int dfs(int p)
{
	if(p>n) return 0;
	int ans=0;
	if(x.top()==a[p])
	{
		ans=a[p];
		x.push(a[p]);
		ans+=dfs(p+1);
		x.pop();
	}
	else if(y.top()==a[p])
	{
		ans=a[p];
		y.push(a[p]);
		ans+=dfs(p+1);
		y.pop();
	}
	else
	{
		x.push(a[p]);
		ans+=dfs(p+1);
		x.pop();
		y.push(a[p]);
		ans=max(dfs(p+1),ans);
		y.pop();
	}
	return ans;
}
signed main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	for(cin>>t;t;--t)
	{
		x.push(0);
		y.push(0);
		cin>>n;
		for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
		cout<<dfs(1)<<endl;
		x.pop();
		y.pop();
	}
	return 0;
}