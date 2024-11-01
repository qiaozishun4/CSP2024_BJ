#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],ans=0,vis[N];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int j=1;
	for(int i=1;i<=n;i++)
	{
		while(a[j]<=a[i]||vis[j]==1)
		{
			j++;
			if(j>n)
				break;
		}
		if(j>n)
			break;
		vis[j]=1;
		ans++;
	}
	cout<<n-ans<<'\n';
	return 0;
}