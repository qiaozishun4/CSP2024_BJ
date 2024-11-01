#include <bits/stdc++.h>
using namespace std;
map<string,bool> mp;
int n,res = 52;
string x;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n ;
	for(int i=1;i<=n;i++)
	{
		cin >> x ;
		if(!mp[x]) 
		{
			res --;
			mp[x] = 1;
		}
	}
	cout << res << "\n";
	return 0;
}