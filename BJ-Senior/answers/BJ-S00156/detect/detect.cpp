#include <bits/stdc++.h>

using namespace std;

struct Segment{
    int l, r;
    bool f;
    Segment() {}
    Segment(int l, int r) : l(l), r(r), f(false) {}
    bool operator<(Segment& s) const {
        if (f == s.f) {
            if (r == s.r) return l > s.l;
            return r > s.r;
        }
        return f > s.f;
    }
};

const int N = 100010, inf = 0x3f3f3f3f, LOGN = 18;
int T, n, m, L, V, r1, p[N], f[N];
multiset<int> P;
vector<Segment> s;

namespace SegmentTree{
    int tr[N << 2];
    void pushup(int u) {
        tr[u] = min(tr[u << 1], tr[u << 1 | 1]);
    }
    void build(int u, int l, int r) {
        // printf("build %d, %d, %d\n", u, l, r);
        fflush(stdout);
        if (l == r) {
            tr[u] = inf;
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
    int query(int u, int l, int r, int s, int t) {
        if (s > t) return inf;
        if (s <= l && r <= t) return tr[u];
        int mid = (l + r) >> 1, res = inf;
        if (s <= mid) res = min(res, query(u << 1, l, mid, s, t));
        if (t > mid) res = min(res, query(u << 1 | 1, mid + 1, r, s, t));
        return res;
    }
    void modify(int u, int l, int r, int p, int x) {
        if (l == r) {
            tr[u] = x;
            return;
        }
        int mid = (l + r) >> 1;
        if (p <= mid) modify(u << 1, l, mid, p, x);
        else modify(u << 1 | 1, mid + 1, r, p, x);
        pushup(u);
    }
};

namespace STable{
    int st[N][LOGN], lg2[N];
    void init() {
        for (int i = 2; i < N; i++) lg2[i] = lg2[i / 2] + 1;
    }
    void build() {
        for (int i = 0; i < s.size(); i++) st[i][0] = s[i].l;
        for (int j = 1; j < LOGN; j++) {
            for (int i = 0; i < s.size(); i++) {
                if (i + (1 << (j - 1)) >= s.size()) st[i][j] = st[i][j - 1];
                else {
                    st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
                    // printf("st[%d][%d] = %d\n", i, j, st[i][j]);
                }
            }
        }
    }
    int query(int l, int r) {
        if (r < l) return inf;
        // cout << "query " << l << " " << r << endl;
        int d = lg2[r - l + 1];
        // cout << "queryd = " << d << endl;
        int t1 = st[l][d], t2 = st[r - (1 << d) + 1][d];
        // printf("t1(%d + %d) = %d t2(%d - %d) = %d\n", l, (1 << d), t1, r, (1 << d) - 1, t2);
        return max(t1, t2);
    }
};

int main() {
    STable::init();
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        P.clear(), s.clear();
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++) {
            int d, v, a;
            cin >> d >> v >> a;
            if (a > 0) {
                if (v > V) s.emplace_back(d, L); // [d, L]
                else {
                    int t = min(L + 1, d + (V * V - v * v) / (2 * a) + 1);
                    // if (t == 844954) {
                    //     cout << d << " " << v << " " << a << endl;
                    // }
                    s.emplace_back(t, L); // [t, L]
                }
            }
            else if (a == 0) {
                if (v > V) s.emplace_back(d, L); // [d, L]
                else s.emplace_back(L + 1, L); // none
            }
            else { // a < 0
                if (v > V) {
                    int t = min(L + 1, d + (v * v - V * V - 1) / (-2 * a));
                    s.emplace_back(d, t); // [d, t]
                }
                else s.emplace_back(L + 1, L); // none
            }
            // cout << "INSERT: " << "[" << s.back().l << "," << s.back().r << "]"<< endl;
        }
        for (int i = 1; i <= m; i++) {
            cin >> p[i];
            P.insert(p[i]);
        }
        // if (T != 19) break;
        // if (T != 14) continue; 
        // remove
        sort(p + 1, p + 1 + m, greater<int>());
        r1 = 0;
        for (Segment& o : s) {
            if (o.l > o.r) o.f = false;
            else {
                auto it = P.lower_bound(o.l);
                if (it == P.end() || o.r < *it) o.f = false;
                else o.f = true;
            }
            r1 += o.f;
        }
        sort(s.begin(), s.end());
        // s.resize(r1);
        // for (const Segment& o : s) {
        //     cout << "[" << o.l << "," << o.r << "]: " << o.f << endl;
        // }
        s.resize(r1);
        SegmentTree::build(1, 0, r1);
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        SegmentTree::modify(1, 0, r1, 0, 0);
        STable::build();
        // for (int i = 0; i < s.size(); i++) cout << "l[" << i << "] = " << s[i].l << endl;
        for (int i = 1, l = 0, r = -1; i <= m; i++) {
            while (r < r1 - 1 && s[r + 1].r >= p[i]) {
                // if (s[r + 1].l > p[i]) l = r + 2;
                r++;
                // printf("[%d, %d]\n", l, r);
            }
            // ----
            // cout << "p[" << i << "] = " << p[i] << endl;
            // for (l = r; l >= 0; l--) {
            //     cout << "l = " << l << endl;
            //     if (s[l].l > p[i]) {
            //         l++;
            //         break;
            //     }
            // }
            // if (l == -1) l = 0;
            // cout << "real l = " << l << endl;
            int L = 0, R = r + 1;
            // int cnt = 0;
            int tmp = STable::query(0, r);
            // printf("[%d, %d] = %d\n", 0, r, tmp);
            if (p[i] >= tmp) l = 0;
            else {
                while (L < R) {
                    // ++cnt;
                    // if (cnt == 10) break;
                    int mid = (L + R) >> 1;
                    // cout << "query" << "[" << mid << "," << r << "]" << endl;
                    int ret = STable::query(mid, r);
                    // cout << "[" << mid << "," << r << "]: " << ret << endl;
                    if (ret <= p[i]) R = mid;
                    else L = mid + 1;
                    // cout << "L = " << L << " R = " << R << endl;
                }
                // if (cnt == 10) exit(0);
            }
            l = L;
            // cout << "my l = " << l << endl;
            // ----
            // while (l <= r && s[l].l >= p[i]) l++;
            // printf("p[%d] = %d, [%d, %d]\n", i, p[i], l, r);
            // fflush(stdout);
            
            // for (int j = l - 1; j < r; j++) f[r + 1] = min(f[r + 1], f[j + 1] + 1);
            f[r + 1] = min(f[r + 1], SegmentTree::query(1, 0, r1, l, r) + 1);
            SegmentTree::modify(1, 0, r1, r + 1, f[r + 1]);
            // cout << "================" << endl;
        }
        cout << r1 << " " << m - f[r1] << endl;
        // break;
    }
    return 0;
}