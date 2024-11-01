#include <bits/stdc++.h>
using namespace std;
int a[1000005],c[1000005];
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	for(int i=1;i<=m;i++) cin>>c[i];
	int T;
	cin>>T;
	while(T--)
	{
		int q,w,e,r;
		cin>>q>>w>>e>>r;
		int s=(a[1]+a[n])*n/2;
		cout<<s%(q+w+e+r)<<endl;
	}
    return 0;
}

