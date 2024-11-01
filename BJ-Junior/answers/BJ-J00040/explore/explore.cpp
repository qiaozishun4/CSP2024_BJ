#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e3 + 5;
struct Node {
    char word;
    bool flag = false;
}arr[MAX][MAX];
int dir[10][10] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int t, n, m, k, nowx, nowy, nowd, ans;
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while (t != 0) {
        t -= 1, ans = 0;
        cin >> n >> m >> k;
        cin >> nowx >> nowy >> nowd;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> arr[i][j].word;
                arr[i][j].flag = false;
            }
        }
        arr[nowx][nowy].flag = true;
        for (int i = 1; i <= k; i++) {
            if (nowx + dir[nowd][0] < 1 || nowx + dir[nowd][0] > n || nowy + dir[nowd][1] < 1 ||
                nowy + dir[nowd][1] > m || arr[nowx + dir[nowd][0]][nowy + dir[nowd][1]].word == 'x') {
                nowd = (nowd + 1) % 4;
            }
            else {
                nowx += dir[nowd][0], nowy += dir[nowd][1];
                arr[nowx][nowy].flag = true;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i][j].flag == true)
                    ans += 1;
            }
        }
        cout << ans << endl;
    }
    fclose(stdin), fclose(stdout);
    return 0;
}