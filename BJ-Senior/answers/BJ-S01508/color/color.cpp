#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
bool color[N];
int a[N];
int ans=0;
inline int calc()
{
	int res=0;
	int precolor[2]={-1,-1};
	for(int i=0;i<n;i++)
	{
		int now=0;
		if(precolor[color[i]]==-1) now=0;
		else if(a[precolor[color[i]]]!=a[i]) now=0;
		else now=a[i];
		precolor[color[i]]=i;
		res+=now;
	}
	return res;
}
void dfs(int x)
{
	if(x==n)
	{
		ans=max(ans,calc());
		return;
	}
	color[x]=1;
	dfs(x+1);
	color[x]=0;
	dfs(x+1);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		ans=0;
		dfs(0);
		cout<<ans<<endl;
	}
	return 0;
}