#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,m=0; cin>>n;
	for (int i=1;i<=n;i++)
	{
		int tm;
		cin>>tm;
		a[tm]++;
	}
	for(int i=1;i<=100000;i++) m=max(m,a[i]);
	cout<<m;
	return 0;
}
