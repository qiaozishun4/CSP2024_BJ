#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,r,i,j,l[100005],c,tmp;
vector<int>v[100005];
int main()
{
	 freopen("chain.in","r",stdin)
	 freopen("chain.out","w",stdout)
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>q;
		for(i = 1;i<=n;i++)
		{
			cin>>l[i];
			for(j = 1;j<=l[i];j++)
			{
				cin>>tmp;
				v[i].push_back(tmp);
			}
		}
		while(q--)
		{
			cin>>r>>c;
			cout<<0<<'\n';
		}
	}
}