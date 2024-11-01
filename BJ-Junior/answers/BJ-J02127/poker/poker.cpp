#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	unordered_set<string> s;
	int n;
	string s1;
	cin>>n;
	while(n--)
	{
		cin>>s1;
		s.insert(s1);
	}
	cout<<52-s.size();
	return 0;
}
