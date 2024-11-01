#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define ll __int128
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
int n,r[100010];
multiset<int>st;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	fre("duel");
	cin>>n;
	for(int i=1;i<=n;++i)cin>>r[i],st.insert(r[i]);
	int ans=n;
	for(int i=1;i<=n;++i){
		auto it=st.upper_bound(r[i]);
		if(it!=st.end()){
			--ans,st.erase(it);
		}
	}
	cout<<ans<<'\n';
	return 0;
}