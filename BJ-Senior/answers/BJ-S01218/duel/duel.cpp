#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int a[MAXN],now,n;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	now=1;
	for(int i=1;i<=n;i++)
	{
		while(now<=n&&a[now]<=a[i]) now++;
		if(now>n)
		{
			cout<<n-i+1;
			return 0;
		}
		now++;
	}
	return 0;
}