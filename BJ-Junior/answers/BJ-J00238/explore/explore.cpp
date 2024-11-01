#include<bits/stdc++.h>
using namespace std;

// #define MY_DBG

const int maxn = 1e3 + 10;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m, k, posx, posy, head, ans;
char maze[maxn][maxn];

inline bool inb(const int x, const int y){
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T--){
		cin >> n >> m >> k >> posx >> posy >> head;
		memset(maze, 'x', sizeof(maze)), ans = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				cin >> maze[i][j];
		maze[posx][posy] = 'w';
		for(int i = 0; i <= k;){
			for(int cnt = 0; cnt < 4;head = (head + 1) % 4, ++cnt){
				++i;
				if(i > k) break;
				const int nx = posx + dx[head];
				const int ny = posy + dy[head];
				#ifdef MY_DBG
				cout << nx << ' ' << ny << ' ' << i << '\n';
				#endif
				if(inb(nx, ny) && maze[nx][ny] != 'x'){
					posx = nx, posy = ny;
					maze[posx][posy] = 'w';
					break;
				}
			}
		}
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				if(maze[i][j] == 'w')
					ans++;
		cout << ans << '\n';
	}
	return 0;
}