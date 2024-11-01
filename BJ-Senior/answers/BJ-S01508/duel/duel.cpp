#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int t[N];
int n;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		t[i]=a[i];
	}
	sort(a,a+n);
	int ans=n;
	for(int i=0;i<n;i++)
	{
		int x=upper_bound(t,t+n,a[i])-t;
		if(t[x]<a[i])
		{
			break;
		}
		ans--;
		t[i]=0;
	}
	cout<<ans;
	return 0;
}