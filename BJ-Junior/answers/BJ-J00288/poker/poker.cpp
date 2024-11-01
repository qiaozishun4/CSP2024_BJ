#include <bits/stdc++.h>
using namespace std;
const int N=60;
int n;
string s;
unordered_set<string> p;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>s;
		p.insert(s);
	}
	int siz=p.size();
	int ans=max(0,52-siz);
	cout<<ans<<"\n";
	return 0;
}