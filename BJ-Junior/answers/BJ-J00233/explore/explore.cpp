#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3+5, MAXM = 1e3+5;

int T, n, m, k, posx, posy, dir, tot;
int mv[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mp[MAXN][MAXM];
bool vis[MAXN][MAXM];

bool Out(int x, int y){
	if (x<1 || y<1 || x>n || y>m) return true;
	return false;
}

void init(){
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			vis[i][j] = false;
		}
	}
	tot = 0;
	return;
}

int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &n, &m, &k);
		scanf("%d%d%d", &posx, &posy, &dir);
		for (int i=1; i<=n; i++){
			for (int j=1; j<=m; j++){
				cin >> mp[i][j];
			}
		}
		init();
		vis[posx][posy] = true;
		tot++;
		for (int i=1; i<=k; i++){
			int nx = posx+mv[dir][0], ny = posy+mv[dir][1];	
			if (Out(nx, ny) == true){
				dir = (dir+1)%4;
			}
			else if (mp[nx][ny] == 'x'){
				dir = (dir+1)%4;
			}
			else{
				posx = nx;
				posy = ny;
			}
			if (vis[posx][posy] == false){
				vis[posx][posy] = true;
				tot++;
			}
		}
		printf("%d\n", tot);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}