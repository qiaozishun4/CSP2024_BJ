#include<bits/stdc++.h>
using namespace std;
const int N=1e5+105;
int n,r[N],a[N],t,ans;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>r[i],a[r[i]]++;
	t=a[1];
	for(int i=2;i<=N-100;i++)
	{
		if(a[i]==0) continue;
		ans+=min(t,a[i]);
		if(t<a[i]) t=a[i];
	}
	cout<<n-ans;
}
