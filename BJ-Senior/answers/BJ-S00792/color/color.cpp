#include<bits/stdc++.h>
using namespace std;
const int Maxn=2e3+10;
int n,ans;
int a[Maxn];
void dfs(int now,int sum,int red,int blue)
{
	if(now==n+1)
	{
		ans=max(sum,ans);
		return ;
	}
	if(a[now]==red) dfs(now+1,sum+red,red,blue);
	else dfs(now+1,sum,a[now],blue);
	if(a[now]==blue) dfs(now+1,sum+blue,red,blue);
	else dfs(now+1,sum,red,a[now]);
}
void run()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans<<endl;
	return ;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--) run();
	return 0;
}