#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>

const int N = 1e5 + 1;
int T, n, m, L, V, d[N], v[N], a[N], p[N], cnt[N], ans = 0;
std::vector<int> shoot[N];

class Double {
    double data;
public:
    Double(double other = 0) {
        data = other;
    }
    bool operator == (const Double other) const {
        return std::fabs(data - other.data) < 1e-6;
    }
    bool operator <= (const Double other) const {
        return data < other.data or *this == other;
    }
};

inline Double speed(int v0, int a, int s) {
    if (v0 * v0 + 2 * a * s < 0)
        return Double(0);
    return Double(std::sqrt(v0 * v0 + 2 * a * s));
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    for (scanf("%d", &T); T--; ) {
        scanf("%d%d%d%d", &n, &m, &L, &V);
        ans = 0;
        memset(cnt, 0, sizeof cnt);
        for (int i = 1; i <= m; ++i)
            shoot[i].clear();
        for (int i = 1; i <= n; ++i)
            scanf("%d%d%d", d + i, v + i, a + i);
        for (int i = 1; i <= m; ++i)
            scanf("%d", p + i);
        std::sort(p + 1, p + n + 1);
        Double sp;
        for (int i = 1, in, flag; i <= n; ++i) {
            for (in = 1; in <= m; ++in)
                if (p[in] >= d[i])
                    break;
            flag = 0;
            for (int j = in; j <= m; ++j) {
                sp = speed(v[i], a[i], p[j] - d[i]);
                if (sp <= Double(0))
                    break;
                if (not (sp <= V)) {
                    flag = 1;
                    ++cnt[i];
                    shoot[j].push_back(i);
                }
            }
            ans += flag;
        }
        printf("%d ", ans);
        ans = 0;
        for (int i = 1, c; i <= m; ++i) {
            c = true;
            for (auto j : shoot[i])
                if (cnt[j] == 1) {
                    c = false;
                    break;
                }
            if (c) {
                for (auto j : shoot[i])
                    --cnt[j];
                ++ans;
            }
        }
        printf("%d\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
