#include<bits/stdc++.h>
using namespace std;
int n,i,cnt[100005],r[100005],ans;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(i = 1;i<=n;i++)
	{
		cin>>r[i];
		cnt[r[i]]++;
		ans = max(ans,cnt[r[i]]);
	}
	cout<<ans;
}