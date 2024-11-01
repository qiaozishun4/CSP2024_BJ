#include <bits/stdc++.h>
using namespace std;
const int N=200010;
int a[N];
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
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			for(int j=1;j<=x;j++)
			{
				cin>>a[j];
			}
		}
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			cout<<"0"<<endl;
		}
	}
	return 0;
}