#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+1;
int n,r[N],b[N];
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		b[r[i]]++;
	}
	int ans=0;
	for(int i=0;i<=100000;i++){
		ans=max(ans,b[i]);
	}
	cout<<ans<<"\n";
	return 0;
}
