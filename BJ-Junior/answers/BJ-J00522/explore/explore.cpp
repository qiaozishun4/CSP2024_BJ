#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
struct point {
    int x, y;
    bool operator< (const point& r) const {
        if (x == r.x) return y < r.y;
        return x < r.x;
    }
};
set<point> se;
int forest[maxn][maxn];
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        se.clear();
        int n, m, k, start_d;
        point start_p;
        cin >> n >> m >> k >> start_p.x >> start_p.y >> start_d;
        se.insert(start_p);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char c;
                cin >> c;
                if (c == '.') forest[i][j] = 0;
                else if (c == 'x') forest[i][j] = 1;
            }
        }
        int cur_d = start_d;
        point cur_p = start_p;
        for (int i = 1; i <= k; i++) {
            point new_p = cur_p;
            new_p.x += dx[cur_d];
            new_p.y += dy[cur_d];
            if (new_p.x < 1 || new_p.x > n || new_p.y < 1 || new_p.y > m || forest[new_p.x][new_p.y] == 1) {
                cur_d = (cur_d + 1) % 4;
            }
            else {
                se.insert(new_p);
                cur_p = new_p;
            }
        }
        cout << se.size() << endl;
    }
    return 0;
}

