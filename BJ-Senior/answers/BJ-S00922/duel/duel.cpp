#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
ll n,a[100005],cnt;
int main()
{
	faster;
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;cnt=n;
	for (ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll l=1,r=1;
	while (r<=n)
	{
		if (a[l]<a[r])
		{
			cnt--;
			l++;
		}
		r++;
	}
	cout<<cnt;
	return 0;
}
