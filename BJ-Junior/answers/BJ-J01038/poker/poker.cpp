#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
string a,b={'A','2','3','4','5','6','7','8','9','T','J','Q','K'},c={'D','C','H','S'};
map<string,bool> mp;
signed main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a;
		mp[a]=1;
	}
	for(int i=0;i<52;++i)
	{
		a[0]=c[i/13];
		a[1]=b[i%13];
		if(!mp[a]) ans++;
	}
	cout<<ans;
	return 0;
}