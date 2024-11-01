#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,tmp,tmp1;
int a[100005],ans;
signed main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[i-1]) tmp+=tmp1,tmp1=0;
		if(tmp) ans--,tmp--;
		tmp1++;
	}
	cout<<ans<<endl;
}