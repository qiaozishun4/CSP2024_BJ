//T1.cpp
#include<bits/stdc++.h>
using namespace std;
int n;
set<string> se;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		se.insert(s);
	}
	cout<<52-se.size();
	fclose(stdin);
	fclose(stdout);
	return 0;
}