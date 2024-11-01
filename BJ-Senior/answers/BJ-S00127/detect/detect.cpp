#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 100000 + 5;
int t;
int n, m, L, V;
int d[N], v[N], a[N];
int p[N];
bool vis[100005];
int ans;
typedef pair<int, int> PII;
vector<PII> cp;
bool cmp(PII x, PII y) {
    if (x.first != y.first) {
        return x.first < y.first;
    }
    return x.second < y.second;
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++) {
            cin >> d[i] >> v[i] >> a[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> p[i];
        }
        sort(p + 1, p + 1 + m);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[j] > p[i]) {
                    continue;
                }
                int s = p[i] - d[j];
                double speed = sqrt(v[j] * v[j] + 2 * a[j] * s);
                if (speed > V) {
                    cp.push_back(make_pair(j, i)); // c(j)p(i)
                    if (!vis[j]) {
                        vis[j] = true;
                        ans++;
                    }
                }
            }
        }

        sort(cp.begin(), cp.end(), cmp);
        int l = 0;
        int count = 0;
        for (int i = 1; i < cp.size(); i++) {
            if (cp[i].first > cp[l].second) {
                l = i, count++;
            }
        }
        cout << ans << " " << m - count << endl;
        ans = 0;
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}
