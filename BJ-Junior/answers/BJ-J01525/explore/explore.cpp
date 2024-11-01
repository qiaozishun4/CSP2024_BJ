#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, m;

char mp[N][N];

bool vis[N][N];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool in(int x, int y){
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main(){
	freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        int k, sx, sy, sd;
        cin >> n >> m >> k >> sx >> sy >> sd;
        for(int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                vis[i][j] = 0;
            }
        }
        int x = sx, y = sy, d = sd;
        vis[sx][sy] = 1;
        while(k--){
            int nx = x + dx[d], ny = y + dy[d];
            if(in(nx, ny) && mp[nx][ny] == '.'){
                vis[nx][ny] = 1; x = nx, y = ny;
            }else{
                d = (d + 1) % 4;
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(vis[i][j]) ans++;
            }
        }
        cout << ans << endl;
    }
}
