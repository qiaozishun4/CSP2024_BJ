#include <bits/stdc++.h>
using namespace std;
map<string,bool> mp;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		if(mp[s])
		{
			n--;
			i--;
		}
		else
		mp[s]=1;
	}
	cout<<52-n;
}
