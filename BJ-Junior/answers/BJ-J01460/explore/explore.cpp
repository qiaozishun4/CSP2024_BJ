#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 5;

int p[MAX][MAX];
int cnt[MAX][MAX];

int walk[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int n, m, k;

void dp(int x, int y, int d, int i) {
    if(i == k) return ;

    if(p[ x + walk[d][0] ][ y + walk[d][1] ]) {
        int nx = x + walk[d][0];
        int ny = y + walk[d][1];
        if(cnt[nx][ny]) dp(x, y, d, k);
        else{
            cnt[nx][ny] = 1;
            dp(nx, ny, d, i+1);
        }
    }
    else dp(x, y, (d+1)%4, i+1);

    return ;
}

int x, y, d;

int t;

char c;

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    cin >> t;
    while(t--) {
        int ans = 0;

        cin >> n >> m >> k;

        for(int i = 0; i <= n + 1; i++) {
            for(int j = 0; j <= m+1; j++) {
                p[i][j] = cnt[i][j] = 0;
            }
        }

        cin >> x >> y >> d;

        cnt[x][y] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> c;
                if(c == '.') p[i][j] = 1;
            }
        }

        dp(x, y, d, 0);

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) ans += cnt[i][j];

        cout << ans << endl;
    }


    return 0;
}
