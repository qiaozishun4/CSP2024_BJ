#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int T, n, m, k;
int sx, sy, t;

char g[N][N];
bool vis[N][N];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int dfs(){
    memset(vis, false, sizeof vis);

   // cout << k << '\n';
    sx --;
    sy --;
    int cnt = 1;
    vis[sx][sy] = true;
    while (k--){
        int a = sx + dx[t], b = sy + dy[t];

     //   cout << t << ' ' << sx << ' ' << sy << ' ' << a <<  ' ' << b << '\n';;
        if (a < 0 || a >= n || b < 0 || b >= m) {t = (t + 1) % 4;}
        else if (g[a][b] == 'x') {t = (t + 1) % 4;}
        else {
            if (!vis[a][b]){
                cnt ++;
                vis[a][b] = true;
            }
            sx = a, sy = b;
        }
    }

    return cnt;
}

int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    cin >> T;
    while (T--){
        scanf("%d%d%d", &n, &m, &k);
        scanf("%d%d%d", &sx, &sy, &t);
        t %= 4;
        for(int i = 0; i < n; i++) {scanf("%s", &g[i]);}

        cout << dfs() << '\n';
    }

    return 0;
}
