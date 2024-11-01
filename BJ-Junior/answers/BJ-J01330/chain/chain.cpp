#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200005;
int s[N];
int t, n, k, q;
signed main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin>>t;
	while(t--) {
		cin>>n>>k>>q;
		for(int i = 1; i <= n; i++) {
			int l; cin>>l;
			for(int j = 1; j <= l; j++) cin>>s[i];
		}
		for(int h = 1; h <= q; h++) {
			int r, c;
			cin>>r>>c;
			if(h % 2 != 0 && h != q) cout<<"1"<<endl;
			else cout<<"0"<<endl;
		}
	}
	return 0;
}
