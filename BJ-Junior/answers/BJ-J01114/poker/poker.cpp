#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0)
ll n,cnt;
string s;
map<string,bool>used;
int main()
{
	faster;
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for (ll i=1;i<=n;i++)
	{
		cin>>s;
		if (!used[s])cnt++;
		used[s]=1;
	}cout<<52-cnt;
	return 0;
}
