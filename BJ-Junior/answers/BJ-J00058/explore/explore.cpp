#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
typedef pair<int, int> pii;

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

char s[N][N];
bool vis[N][N];

int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--){
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		int sx, sy, sd;
		scanf("%d%d%d", &sx, &sy, &sd);
		for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				vis[i][j] = false;
			}
		}
		
		vis[sx][sy] = true;
		while(k--){
			int nx = sx + dx[sd], ny = sy + dy[sd];
			
			if(nx > n || nx < 1 || ny > m || ny < 1 || s[nx][ny] == 'x') sd = (sd + 1) % 4;
			else{
				sx = nx;
				sy = ny;
			}
			vis[sx][sy] = true;
		}
		
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(vis[i][j]) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}