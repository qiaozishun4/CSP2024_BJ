#include<bits/stdc++.h>
using namespace std;
int vis[100005],ans;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,mx=0,mn=INT_MAX,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(x>mx)
			mx=x;
		if(x<mn)
			mn=x;
		vis[x]++;
	}
	for(int i=mn;i<=mx;i++)
		ans=max(ans,vis[i]);
	cout<<ans<<endl;
	return 0;
}