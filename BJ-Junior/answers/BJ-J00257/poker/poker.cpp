#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
map<string,int> m;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		string s;
		cin>>s;
		m[s]++;
	}
	cout<<52 - m.size();
	return 0;
}
