#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,i;
	string str;
	set<string> s;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>str;
		s.insert(str);
	}
	cout<<(52-s.size());
	return 0;
}
