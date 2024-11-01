#include <bits/stdc++.h>
using namespace std;
int T, n, m, L, V, p[100005], d[100005], v[100005], a[100005], tmp[1000005], vis[100005];
vector<pair<int, int> > G;
struct node {
    int l, r;
} ss[100005];
int popcount(int x) {
    int sum = 0;
    while(x) sum += x % 2, x /= 2;
    return sum;
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%d", &T);
    while(T--) {
        G.clear();
        int ans = 100000, cnt = 0;
        scanf("%d%d%d%d", &n, &m, &L, &V);
        memset(tmp, 0, sizeof tmp);
        for(int i = 1; i <= n; i++) {
            scanf("%d%d%d", &d[i], &v[i], &a[i]);
            if(a[i] == 0) {
                if(v[i] > V) G.push_back({d[i], L});
            } else if(a[i] > 0) {
                int tmp = V * V - v[i] * v[i];
                int tmp2 = (tmp % (2 * a[i]) == 0 ? tmp / (2 * a[i]) + 1 : tmp / (2 * a[i]));
                if(d[i] + tmp2 <= L) G.push_back({d[i] + tmp2, L});
            } else {
                int tmp = V * V - v[i] * v[i];
                int tmp2 = (tmp % (2 * a[i]) == 0 ? tmp / (2 * a[i]) - 1 : tmp / (2 * a[i]));
                G.push_back({d[i], min(d[i] + tmp2, L)});
            }
        }
        for(int i = 1; i <= m; i++) scanf("%d", &p[i]), tmp[p[i]] = 1;
        for(int i = 1; i <= L; i++) tmp[i] += tmp[i - 1];
        for(int i = 0; i < G.size(); i++) {
            int x = G[i].first, y = G[i].second;
            if(tmp[y] != tmp[x - 1]) ss[++cnt] = {x, y};
        }
        for(int i = 0; i < (1 << m); i++) {
                if(popcount(i) > ans) continue;
            int tt = 0;
            for(int j = 1; j <= cnt; j++) vis[j] = 0;
            for(int j = 1; j <= m; j++) {
                if((i >> j - 1) & 1) {
                    tt++;
                    for(int k = 1; k <= cnt; k++) if(p[j] >= ss[k].l && p[j] <= ss[k].r) vis[k] = 1;
                }
            }
            int flag = 1;
            for(int j = 1; j <= cnt; j++) if(!vis[j]) {
                flag = 0;
                break;
            }
            if(flag) ans = min(ans, tt);
        }
        cout << cnt << " " << m - ans << endl;
    }
    return 0;
}
