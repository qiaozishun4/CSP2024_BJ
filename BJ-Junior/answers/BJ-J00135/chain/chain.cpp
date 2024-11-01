#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,l[100005],qz[100005],zz[200005],r,c,as;
bool dp[200005][105];
void sv(){
	cin >> n >> k >> q;
	qz[0]=0;
	for(int i=1;i<=n;i++){
		cin >> l[i];
		for(int j=qz[i-1]+1;j<=qz[i-1]+l[i];j++){
			cin >> zz[j];
		}
		qz[i]=qz[i-1]+l[i];
	}
	while(q--){
		cin >> r >> c;
		cout << dp[c][r] << "\n";
	}
	return;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		sv();
	}
	return 0;
}
