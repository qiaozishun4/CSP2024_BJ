#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans;
int r[N],cnt[N];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
		cnt[r[i]]++;
	}
	int last=0;
	for(int i=N;i>=1;i--)
	{
		if(cnt[i]!=0)
		{
			if(last!=0) ans+=max(0,cnt[i]-last);
			else ans+=cnt[i];
			last=ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}