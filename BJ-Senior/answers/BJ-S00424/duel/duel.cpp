#include <bits/stdc++.h>
using namespace std;
int a[100010],book[100010];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stsdio(0);
	cin.tie(0);
	cout.tie(0);

	int i,j,k,n,m,maxn=-1;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		book[a[i]]++;
	}
	for(i=1;i<=n;i++) maxn=max(maxn,book[a[i]]);
	cout<<maxn;
}