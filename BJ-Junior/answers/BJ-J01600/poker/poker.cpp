#include <bits/stdc++.h>
using namespace std;
int cnt;
map<string,int>mp;

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		if(!mp.count(s))
		{
			cnt++;
			mp[s]=1;
		}
	}
	cout<<52-cnt<<endl;
	return 0;
}