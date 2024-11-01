#include<bits/stdc++.h>
#define int long long
#define faster; ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,ans,a[200005];
signed main()
{
	faster;
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==a[i-1])ans+=a[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}