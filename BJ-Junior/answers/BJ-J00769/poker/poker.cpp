#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=60;
map<string,bool>mp;
string s[N];
int n,cnt;
signed main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(mp[s[i]])
		{
			continue;
		}
		mp[s[i]]=true;
		cnt++;
	}
	cout<<52-cnt;
	exit(0);
}