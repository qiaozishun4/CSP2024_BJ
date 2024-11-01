#include <bits/stdc++.h>
using namespace std;
int n,ans;
string s;
map <string,bool> mp;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for (int i = 1;i <= n;i++)
	{
		cin>>s;
		if (!mp[s])
		{
			ans++;
			mp[s] = 1;
		}
	}
	cout<<52-ans;
	return 0;
}
