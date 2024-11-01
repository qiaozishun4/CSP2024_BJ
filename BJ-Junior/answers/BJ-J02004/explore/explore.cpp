#include <bits/stdc++.h>
using namespace std;
const int INF = 1e3 + 10;
int T;
int n, m, k;
char mp[INF][INF];
bool vis[INF][INF];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
long long cnt = 1;
void Gofind(int sx, int sy, int k, int d){
	if(k == 0){
		return ;
	}
	//printf("k = %d (%d, %d)\n", k, sx, sy);
	for(int i = d; ; i = (i + 1) % 4){
		int fx = sx + dx[i];
		int fy = sy + dy[i];
		if(fx <= n && fx >= 1 && fy <= m && fy >= 1 && mp[fx][fy] == '.'){
			if(vis[fx][fy] == false) cnt++;
			vis[fx][fy] = true;
			k--;
			Gofind(fx, fy, k, i);
			break;
		} else {
			if(k > 0){
				k--;
				//printf("k = %d turn\n", k);
			}
			if(k == 0) break;
		}
	}
}
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		cnt = 1;
		memset(vis, 0, sizeof(vis));
		int sx0, sy0, sd0;
		scanf("%d%d%d", &n, &m, &k);
		scanf("%d%d%d", &sx0, &sy0, &sd0);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> mp[i][j];
			}
		}
		if(mp[sx0][sy0+1] != '.' || sy0+1 > m){
			if(mp[sx0][sy0-1] != '.' || sy0-1 < 1){
				if(mp[sx0+1][sy0] != '.' || sx0+1 > n){
					if(mp[sx0-1][sy0] != '.' || sx0-1 < 1){
						printf("1\n");
						continue;
					}
				}
			}
		}
		vis[sx0][sy0] = true;
		Gofind(sx0, sy0, k, sd0);
		printf("%lld\n", cnt);
	}
	return 0;
}
