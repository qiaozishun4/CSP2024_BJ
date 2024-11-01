#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
int T, n, m, l, v0, d[N], v[N], a[N], p[N], cnt, cnt2, vv[N];
vector<int> vis[N];
map<int, int> mp;
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
    cin >> T;
    while (T --) {
        cin >> n >> m >> l >> v0;
        cnt = 0;
        for (int i = 1; i <= n; i ++) {
            cin >> d[i] >> v[i] >> a[i];
        }
        for (int i = 1; i <= m; i ++) cin >> p[i];
        memset(vis, 0, sizeof(vis));
        cnt2 = 0;
        for (int i = 1; i <= n; i ++) {
            if (v0 >= v[i] && a[i] <= 0) continue;
            if (a[i] == 0 && v0 < v[i]) {
                cnt ++;
                for (int j = 1; j <= m; j ++) if (p[j] >= d[i]) vis[j].push_back(i);
                mp[i] = 1;
                continue;
            } else if (a[i] == 0) continue;
            bool flag = 0;
            double dis = (v0 * v0 - v[i] * v[i]) / 2.0 / a[i];
            double st = d[i], ed = d[i] + dis;
            if (dis < 0) {
                if (v0 > v[i]) continue;
                for (int j = 1; j <= m; j ++) if (p[j] >= st) vis[j].push_back(i), flag = 1;
                if (flag) cnt ++, mp[i] = 1;
                continue;
            }
            if (dis == 0) {
                if (a[i] < 0) continue;
                for (int j = 1; j <= m; j ++) if (p[j] > st) vis[j].push_back(i), flag = 1;
                if (flag) cnt ++, mp[i] = 1;
                continue;
            }
            if (v0 > v[i]) {
                for (int j = 1; j <= m; j ++) if (p[j] > ed) vis[j].push_back(i), flag = 1;
                if (flag) cnt ++, mp[i] = 1;
            }
            else {
                for (int j = 1; j <= m; j ++) if (p[j] >= st && p[j] < ed) vis[j].push_back(i), flag = 1;
                if (flag) cnt ++, mp[i] = 1;
            }

        }
        cout << cnt << ' ';
        for (int i = 1; i <= m; i ++) sort(vis[i].begin(), vis[i].end());
        for (int i = 1; i <= m; i ++) {
            for (int j = i + 1; j <= m; j ++) {
                if (vis[i].size() <= vis[j].size()) {
                    vector<int> tp = vis[i];
                    vis[i] = vis[j];
                    vis[j] = tp;
                }
            }
        }
        /*for (int i = 1; i <= m; i ++) {
            if (!vis[i].size()) continue;
            for (auto j : vis[i]) cout << j << ' ';
            cout << '\n';
        }*/
        for (int i = 1; i <= m; i ++) {
            for (int j = 0; j < vis[i].size(); j ++) {
                vv[vis[i][j]] = 1;
            }
            int flag = 0;
            for (int j = 1; j <= n; j ++) if (vv[j] && mp.count(j)) flag ++;
            if (flag == cnt) {
                cnt2 = m - i;
                break;
            }
        }
        cout << cnt2 << '\n';
    }
    return 0;
}
