#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double d[100005], v[100005], a[100005], p[100005];
int ans, o[100005];
struct node{
    queue<int> qu;
} q[100005]; // 每个车超的速
struct no {
    int id, num; queue<int> r;
} c[100005]; //每个测速器连的车
bool cmp(no x, no y) {
    return x.num > y.num;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T; cin >> T;
    while (T--) {
        int n, m; double L, V; cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++) cin >> d[i] >> v[i] >> a[i];
        for (int i = 1; i <= m; i++) {
            cin >> p[i];
            c[i].id = p[i];
        }
        for (int i = 1; i <= n; i++) {
            double num = 0; int num1 = 0, num2 = 0;
            if (v[i] > V && a[i] >= 0) {
                num1 = d[i], num2 = 15;//超速
            }
            if (v[i] < V && a[i] > 0) {
                num = (V * V - v[i] * v[i]) / (2 * a[i]);//num为速度恰好为V时的路程
                num1 = num + d[i];
                if ((ll)(V * V - v[i] * v[i]) % (ll)(2 * a[i]) != 0) num1++;
                num2 = 15;
            }
            if (v[i] > V && a[i] < 0) {
                num = (V * V - v[i] * v[i]) / (2 * a[i]);//num为速度恰好为V时的路程
                num2 = d[i] + num;
                if ((ll)(V * V - v[i] * v[i]) % (ll)(2 * a[i]) != 0) num2++;
                num1 = d[i];
            }
            int ooo = num1, o2 = num2;
            if (num1 > num2 || (num1 == 0 && num2 == 0)) continue;
            int L = 1, R = m;
            while (L < R) {
                int mid = (L + R) / 2;
                if (p[mid] < num1) L = mid + 1;
                else if (p[mid] > num1) R = mid - 1;
                else {
                    L = mid, R = mid;
                }
            }
            num1 = L;
            L = 1, R = m;
            while (L < R) {
                int mid = (L + R) / 2;
                if (p[mid] < num2) L = mid + 1;
                else if (p[mid] > num2) R = mid - 1;
                else {
                    L = mid, R = mid;
                }
            }
            num2 = L;
            ans++; o[i] = 1;
            for (int j = num1; j <= num2; j++) {
                q[i].qu.push(j);
                c[j].num++; c[j].r.push(i);
            }
        }
        cout << ans << " ";
        int ans2 = 0;
        while (ans) {
            ans2++;
            sort(c + 1, c + n + 1, cmp);
            c[1].num = 0;
            while (!c[1].r.empty()) {
                int x = c[1].r.front(); c[1].r.pop();
                if (o[x] == 1) {
                    ans--;
                    o[x] = 0;
                    while (!q[x].qu.empty()) {
                        int y = q[x].qu.front(); q[x].qu.pop();
                        c[y].num--;
                    }
                }
            }
        }
        cout << m - ans2 << "\n";
    }
    return 0;
}
