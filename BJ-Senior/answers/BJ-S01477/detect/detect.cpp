#include<bits/stdc++.h>
using namespace std;
int _;
struct CR
{
	int d,v,a;
}cr[100010];
int p[100010];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>_;
	while (_--)
	{
		int n,m,L,V;
		cin>>n>>m>>L>>V;
		int rr=-1,ll=1000000000,cll=1000000000;
		for (int i=1;i<=n;i++)
		{
			cin>>cr[i].d>>cr[i].v>>cr[i].a;
		}
		for (int i=1;i<=m;i++)
		{
			cin>>p[i];
			rr=max(rr,p[i]);
			ll=min(ll,p[i]);
		}
		int res1=0;
		for (int i=1;i<=n;i++)
		{
			if (cr[i].d<=rr&&cr[i].v>V)
			{
				res1++;
				cll=min(cll,cr[i].d);
			}
		}
		int res2=(rr<cll?m:m-1);
		cout<<res1<<" "<<res2<<'\n';
	}
	return 0;
}
