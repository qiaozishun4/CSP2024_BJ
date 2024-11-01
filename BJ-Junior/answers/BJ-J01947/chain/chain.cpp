#include <bits/stdc++.h>
using namespace std;
int cnt[200005],s[1005][1005],l[1005];
void solve()
{
	int n,k,q;
	cin>>n>>k>>q;
	for(int i=1;i<=200000;i++) cnt[i]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
		cnt[l[i]]=1;
		for(int j=1;j<=l[i];j++) cin>>s[i][j];
	}
	while(q--)
	{
		int r,c;
		cin>>r>>c;
		if(k<c){
			cout<<"0"<<endl;
		}
		else if(cnt[c]==0){
			cout<<"0"<<endl;
		}
		else{
			cout<<"1"<<endl;
		}
	}
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}