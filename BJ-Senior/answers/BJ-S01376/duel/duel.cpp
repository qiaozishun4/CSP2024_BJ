#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int NR=1e5+10;
int n,a[NR],buc[NR];


signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],buc[a[i]]++;
	int ans=0;
	for(int i=1;i<=1e5;i++)ans=max(ans,buc[i]);
	cout<<ans<<endl;
	return 0;
}