#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int n, m, b[N], c[N], d[10][N];
int w[4], a[N];
struct stu {
    int val, id;
    bool operator == (const stu &o) const {
        return val == o.val && id == o.id;
    }
    bool operator < (const stu &o) const {
        return val < o.val;
    }
};
struct dat {
    int cnt;
    multiset<stu> s;
    int sum1, sum2;
};
multiset<stu> merge(multiset<stu> s1, multiset<stu> s2) {
    for (auto it : s2) {
        auto it2 = s1.find(it);
        if (it2 == s1.end()) s1.insert(it);
    }
    return s1;
}
dat solve(int dep, int pos, int lim) {
    if (!dep) {
        multiset<stu> s;
        s.clear();
        if (pos <= lim) s.insert({a[pos], pos});
        if (pos <= lim) return {1, s, pos, 0};
        else return {1, s, 0, pos};
    }
    dat x = solve(dep - 1, (pos << 1) - 1, lim);
    dat y = solve(dep - 1, (pos << 1), lim);
    if (!d[dep][pos]) {
        multiset<stu> t = x.s;
        int flag = 0;
        for (auto it : x.s) {
            if (it.val < dep) {
                auto it2 = t.find(it);
                if (it2 != t.end()) t.erase(it2);
                x.cnt--, x.sum1 -= it.id;
                flag = 1;
            }
        }
        if (x.sum2 != 0) flag = 1;
        return {x.cnt + y.cnt, flag ? merge(t, y.s) : t, flag ? x.sum1 + y.sum1 : x.sum1, flag ? x.sum2 + y.sum2 : x.sum2};
    }
    else {
        multiset<stu> t = y.s;
        int flag = 0;
        for (auto it : y.s) {
            if (it.val < dep) {
                auto it2 = t.find(it);
                if (it2 != t.end()) t.erase(it2);
                y.cnt--, y.sum1 -= it.id;
                flag = 1;
            }
        }
        if (y.sum2 != 0) flag = 1;
        return {x.cnt + y.cnt, flag ? merge(x.s, t) : t, flag ? x.sum1 + y.sum1 : y.sum1, flag ? x.sum2 + y.sum2 : y.sum2};
    }
}
void work() {
    for (int i = 0; i < 4; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++) {
        a[i] = b[i] ^ w[i % 4];
        //cout << a[i] << " ";
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int dep = __lg(c[i]);
        if ((1 << dep) != c[i]) dep++;
        dat xx = solve(dep, 1, c[i]);
        ans ^= (i * (xx.sum1 + xx.sum2));
        //cout << (xx.sum1 + xx.sum2) << endl;
    }
    cout << ans << '\n';
}
int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= m; i++)
        cin >> c[i];
    int K = __lg(n);
    if ((1 << n) != K) K++;
    for (int i = 1; i <= K; i++){
        for (int j = 1; j <= (1 << (K - i)); j++){
            char ch;
            cin >> ch;
            d[i][j] = ch - '0';
        }
    }
    int T;
    cin >> T;
    while (T--) work();
    return 0;
}