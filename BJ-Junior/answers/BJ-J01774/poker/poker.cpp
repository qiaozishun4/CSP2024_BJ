#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("poke.in","r",stdin);
	freopen("poke.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	map<pair<int,int>,int>mp;
	int sm=0;
	for (int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		int aa=0,bb=0;
		if (s[0]=='D') aa=1;
		else if (s[0]=='C') aa=2;
		else if (s[0]=='H') aa=3;
		else if (s[0]=='S') aa=4;
		if (s[1]=='A') bb=1;
		else if (s[1]=='T') bb=10;
		else if (s[1]=='J') bb=11;
		else if (s[1]=='Q') bb=12;
		else if (s[1]=='K') bb=13;
		else bb=(int)(s[1]-'0');
		if (mp[make_pair(aa,bb)]==1) continue;
		mp[make_pair(aa,bb)]=1;
		sm++;
	}
	cout<<(52-sm);
	return 0;
}
