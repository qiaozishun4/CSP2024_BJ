#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,L,V;
int d[N];
int v[N];
int tst[N];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>L>>V;
		for(int i=0;i<n;i++)
		{
			int ai;
			cin>>d[i]>>v[i]>>ai;
		}
		int maxt=0;
		for(int i=0;i<m;i++)
		{
			cin>>tst[i];
			maxt=max(maxt,tst[i]);
		}
		int ans1=0;
		for(int i=0;i<n;i++)
		{
			if(d[i]<=maxt&&v[i]>V) ans1++;
		}
		if(ans1!=0)
			cout<<ans1<<' '<<m-1<<endl;
		else cout<<0<<' '<<m<<endl;
	}
	return 0;
}