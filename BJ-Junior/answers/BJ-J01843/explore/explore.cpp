#include<bits/stdc++.h>
using namespace std;
int T;
int n, m, k, sx, sy, p;
char g[3005][3005];
int tx[] = {0, 1, 0, -1};
int ty[] = {1, 0, -1, 0};
bool vis[3005][3005];
int mo() {
    int cnt = 1;
    int nowx = sx, nowy = sy, pos = p;
    vis[nowx][nowy] = 1;
    while(k--) {
        int fx = nowx + tx[pos];
        int fy = nowy + ty[pos];
        if(fx > n || fy > m || fx < 1 || fy < 1) {
            pos = (pos + 1) % 4;
            continue;
        }
        if(g[fx][fy] == 'x') {
            pos = (pos + 1) % 4;
            continue;
        }
        if(vis[fx][fy] == 0) {
            cnt++;
        }
        vis[fx][fy] = 1;
        nowx = fx, nowy = fy;
    }
    return cnt;
}
int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--) {
        memset(vis, 0, sizeof vis);
        cin >> n >> m >> k >> sx >> sy >> p;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> g[i][j];
            }
        }
        cout << mo() << "\n";
    }
    return 0;
}
/*
1
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....

*/
