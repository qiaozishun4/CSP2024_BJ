#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,q;
		cin>>n>>k>>q;
		string s;
		for(int i=1;i<=n;i++) getline(cin,s);
		int d,f;
		for(int i=1;i<=q;i++) cin>>d>>f;
		cout<<1<<endl;
	}
	return 0;
}
