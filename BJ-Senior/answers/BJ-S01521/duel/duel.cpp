#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vl=vector<ll>;
const int inf=0x3f3f3f3f;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int n;
	cin>>n;
	vi r(n+1);
	vi bt(100005);
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		bt[r[i]]++;
		ans=max(ans,bt[r[i]]);
	}
	cout<<ans<<endl;
	return 0;
}