#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int vis[N];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	int tt=1;
	while(tt<=T)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			vis[a[i]]++;
		}	
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[a[i]]>=2)
			{
				ans+=a[i]*(vis[a[i]]-1);
				vis[a[i]]=0;
			}
		}
		cout<<ans<<endl;
		ans=0;
		memset(vis,0,sizeof(vis));
		tt++;
	}
	return 0;
}