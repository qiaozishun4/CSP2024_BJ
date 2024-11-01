#include<bits/stdc++.h>
#define int long long
using namespace std;
set<string> s;
signed main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string a;
		cin>>a;
		s.insert(a);
	}
	cout<<52-s.size();
	return 0;
}
