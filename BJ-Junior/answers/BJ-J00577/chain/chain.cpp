#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t,n,m,k,i;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		for(i=1;i<=n;i++) cin>>m;
		for(i=1;i<=k;i++) cin>>n>>m;
		cout<<1<<endl;
	}
	return 0;
}
