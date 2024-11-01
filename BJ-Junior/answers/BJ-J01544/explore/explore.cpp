#include<bits/stdc++.h>
using namespace std;
int dd[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char ch[1010][1010];
bool flag[1010][1010];

int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++){
        memset(flag, false, sizeof(flag));
        int n, m, k;//地图大小和步数
        cin >> n >> m >> k;
        int x, y, d;//初始位置和面朝的方向
        cin >> x >> y >> d;
        for (int j = 1; j <= n; j++)
            for (int kk = 1; kk <= m; kk++)
                cin >> ch[j][kk];
        int ans = 1;
        for (int j = 1; j <= k; j++){
            int dx = x + dd[d][0];
            int dy = y + dd[d][1];
            if ((dx < 1) || (dx > n) || (dy < 1) || (dy > m) || (ch[dx][dy] == 'x')){
                d = (d + 1) % 4;
                if (j == k)
                    break;
                continue;
            }
            if (!flag[dx][dy]){
                ans++;
                flag[dx][dy] = true;
            }
            x = dx;
            y = dy;
        }
        cout << ans << '\n';
    }

    return 0;
}
