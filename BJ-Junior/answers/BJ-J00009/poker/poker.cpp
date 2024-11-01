#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	string a;
	set<string> s;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		s.insert(a);
	}
	cout<<52-int(s.size());
	return 0;
}
