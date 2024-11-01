#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int L = 18;
const int N = 4;
int n, m, k, t, C[N], A[maxn], a[maxn], b[maxn], c[maxn];
string s[L];
vector<vector<int> > calc(vector<vector<int> >& v, string& w, int R) {
    vector<vector<int> > res;
    for (int i = 0; i < v.size(); i += 2) {
        vector<vector<int> > cur = {v[i], v[i ^ 1]};
        vector<int> nxt;
        vector<int> x1 = cur[w[i >> 1] & 1];
        vector<int> x2 = cur[(w[i >> 1] & 1) ^ 1];
        bool F = false;
        for (int x : x1) {
            F |= c[x] == -1 || c[x] <= R;
            if (c[x] > R || c[x] == -1) nxt.push_back(x);
        } if (F) for (int x : x2) nxt.push_back(x);
        res.push_back(nxt);
    } return res;
}
ll solve(int x) {
    ll res = 0; vector<vector<int> > cur;
    int K = 0; while ((1 << K) < x) ++K;
    for (int i = 1; i <= x; i++) c[i] = a[i];
    for (int i = x + 1; i <= 1 << K; i++) c[i] = -1;
    for (int i = 1; i <= 1 << K; i++) {
        vector<int> v; v.push_back(i);
        cur.push_back(v);
    }
    for (int i = 0; i < K; i++) cur = calc(cur, s[i], i);
    for (int x : cur.back()) res += x; return res;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    while ((1 << k) < n) ++k;
    for (int i = 0; i < k; i++) cin >> s[i];
    cin >> t;
    while (t--) {
        for (int i = 0; i < N; i++) cin >> C[i];
        for (int i = 1; i <= n; i++) a[i] = A[i] ^ C[i % 4];
        ll ans = 0;
        for (int i = 1; i <= m; i++) ans ^= (ll)i * solve(b[i]);
        cout << ans << '\n';
    }
    return 0;
}