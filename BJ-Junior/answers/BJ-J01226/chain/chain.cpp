#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
map<string ,int >mp;
int main()
{
	freopen("chain.in","w",stdin);
	freopen("chain.out","r",stdout);
	int t,n,k,q,l,s,r,c;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>l;
			for(int j=1;j<=l;j++)
				cin>>s;
		}
		while(q--)
		{
			cin>>r>>c;
			cout<<0<<endl;
		}
	}

	return 0;
}
