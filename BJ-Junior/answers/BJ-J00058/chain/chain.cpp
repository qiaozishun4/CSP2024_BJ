#include<bits/stdc++.h>
using namespace std;
vector<int> v[100010];
int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--){
		int n, k, q;
		scanf("%d%d%d", &n, &k, &q);
		for(int i = 1; i <= n; i++){
			v[i].clear();
		
			int sz;
			scanf("%d", &sz);
			while(sz--){
				int x;
				scanf("%d", &x);
				v[i].push_back(x);
			}
		}
		
		while(q--){
			int r, c;
			scanf("%d%d", &r, &c);
			if(r == 1){
				bool flag = false;
				for(int i = 1; i <= n; i++){
					int m = v[i].size();
					for(int j = 0; j < m; j++){
						if(v[i][j] == 1){
							for(int t = j + 1; t < j + k; t++) if(v[i][t] == c){
								flag = true;
								break;
							}
						}
					}
					if(flag) break;
				}
				printf("%d\n", flag);
			}
		}
	}
	return 0;
}