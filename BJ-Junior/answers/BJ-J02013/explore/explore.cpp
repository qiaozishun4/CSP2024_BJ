#include <bits/stdc++.h>

using namespace std;

const int NMmax = 1e3 + 7;

int T;

int n, m, k;
int sx, sy, sd;
char mp[NMmax][NMmax];
int book[NMmax][NMmax];
int ans;
int nextx[4] = {0, 1, 0, -1};
int nexty[4] = {1, 0, -1, 0};
int nmax;

void DFS(int step, int x, int y, int d, int num){
	if(step == 0){
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++)
				if(book[i][j] > 1) num -= (book[i][j] - 1);
		ans = max(ans, num);
		return;
	}
	int nx, ny;
	for(int k = 0;k < 4;k++){
		nx = x + nextx[k];
		ny = y + nexty[k];
		if(d == k){
			if(mp[nx][ny] == '.'){
				mp[nx][ny] == '#';
				book[nx][ny]+=1;
				DFS(step-1, nx, ny, d, num+1);
				mp[nx][ny] == '.';
				book[nx][ny]-=1;
			}else
				DFS(step-1, x, y, (d+1)%4, num);
		}
	}
}

int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n >> m >> k;
		cin >> sx >> sy >> sd;
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++)
				cin >> mp[i][j];
		ans = 0;
		book[sy][sx] = 0;
		DFS(k, sx, sy, sd, 1);
		cout << ans << endl;
	}
	return 0;
}