#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0)
ll t,n,biao[]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88},ans[]={888,108,188,200,208,288,688};
int main()
{
	faster;
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while (t--)
	{
		cin>>n;
		if (n<=14)cout<<biao[n]<<"\n";
		else
		{
			cout<<ans[n%7];
			n=(n-1)/7;
			for (ll i=3;i<=n;i++)cout<<8;
			cout<<"\n";
		}
	}
	return 0;
}


