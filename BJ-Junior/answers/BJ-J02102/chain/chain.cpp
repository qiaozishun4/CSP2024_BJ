#include <bits/stdc++.h>
using namespace std;

vector<int> a[100005], all;
int n, k, q, r, c;
bool ans=0;
int bk[200005];
bool dfs(int u, int num, int cnt){
	if(cnt == r+1){
		if(num == c) return 1;
	}
	memset(bk, 0, sizeof(bk));
	int p=a[u].size();
	for(int i=0;i < p;i++){
		if(a[u][i] == num){
			for(int j=i;j < min(p, i+k-1);j++){
				bk[a[u][j]]=1;
			}
			i=min(i+k, p);
		}
	}
	for(int i : all){
		if(bk[i]){
			if(dfs(u%n+1, i, cnt+1)) return 1;
			// cout << "ok\n";
		}
	}
	return 0;
}
int main(){
	// freopen("chain.in", "r", stdin);
	// freopen("chain.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		for(int i=1;i <= 100000;i++){
			a[i].clear();
		}
		all.clear();
		cin >> n >> k >> q;
		for(int i=1;i <= n;i++){
			int m;
			cin >> m;
			for(int j=1;j <= m;j++){
				cin >> c;
				a[i].push_back(c);
				all.push_back(c);
			}
		}
		for(int i=1;i <= q;i++){
			ans=0;
			cin >> r >> c;
			if(dfs(i, 1, 1)){
				ans=1;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}