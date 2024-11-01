#include<bits/stdc++.h>
using namespace std;
namespace solve
{
	constexpr int N=100000;
	int n;
	int r[N+5],f[N+5];
	void sol()
	{
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			cin>>r[i];
			f[r[i]]++;
		}
		int res=0;
		for(int i=1;i<=N;++i)
		{
			res-=min(f[i],res);
			res+=f[i];
		}
		cout<<res<<endl;
		return;
	}
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	solve::sol();
	return 0;
}
