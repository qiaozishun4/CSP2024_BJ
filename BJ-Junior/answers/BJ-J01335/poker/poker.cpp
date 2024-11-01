#include <iostream>
#include <map>
using namespace std;
map<string,int> mp;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=0;
	string s;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>s;
		if (mp[s]==0)
		{
			ans++;
			mp[s]=1;
		}
	}
	cout<<52-ans;
	return 0;
}