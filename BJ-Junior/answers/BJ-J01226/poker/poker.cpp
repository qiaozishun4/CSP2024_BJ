#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
map<string ,int >mp;
int main()
{
	freopen("poker.in","w",stdin);
	freopen("poker.out","r",stdout);
	int n,ans=0;
	mp.clear();
	string s;
	cin>>n;
	while(n--)
	{
			cin>>s;
			mp[s]++;
			if(mp[s]==1)
				ans++;
	}
	cout<<52-ans;


	return 0;
}
