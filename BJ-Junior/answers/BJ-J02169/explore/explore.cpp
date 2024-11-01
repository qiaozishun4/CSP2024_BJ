#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int T;
char c[N][N];
int n, m, k;
long long sum;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool vis[N][N];

int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);

	cin >> T;
	while(T --){
		cin >> n >> m >> k;
		int x, y, d;
		cin >> x >> y >> d;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++){
				cin >> c[i][j];
				vis[i][j] = false;
			}
		
		sum = 1;
		vis[x][y] = true;
		while(k --){
			int a = x + dx[d], b = y + dy[d];

			if(a < 1 || a > n || b < 1 || b > m || c[a][b] == 'x'){
				d = (d + 1) % 4;
			}
			
			else{
				if(!vis[a][b]) sum ++;
				vis[a][b] = true;
				x = a, y = b;
			}

		}

		cout << sum << '\n';
	}
}