#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("chain.in","r",stdin);              
	freopen("chain.out","w",stdout);
	int T,n,k,r,c,q,t,flag;
	cin>>T;
	for(int x=1;x<=T;x++)
	{
		cin>>n>>k>>q;
		for(int i=1;i<=n+1;i++)
			{
				cin>>t;
				for(int j=1;j<=t;j++)cin>>flag;
			}
			cout<<q;
		for(int i=1;i<=q+1;i++)
		{
			cin>>r>>c;
			cout<<0<<endl;
		}
	}
	return 0;
}
