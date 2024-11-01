#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define nrep(i, a, b) for(int i = (a); i >= (b); i --)
using namespace std;

void print() { cerr << endl; }
template<typename T, typename ...Ts>
void print(T v, Ts ...vs) { cerr << v << " "; print(vs...); }


typedef long long ll;
ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
    while(isdigit(ch)) { x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar(); }
    return x * f;
}

const int N = 2e5 + 10;

int n, m, k, tot;
int a[N], b[N], c[N], X[4];
vector<int> d[21];
int f[N][21];
char s[N];

inline void chmax(int &x, int y) { x = max(x, y); }
int get(int x, int y, int lim) {
    if(x >= lim) return x;
    return y;
}
int query(int x, int v) {
    int ans = 0;
    rep(i, 0, v) chmax(ans, f[x][i]);
    return ans;
}

void dfs(int x, int dep) {
    int lim = k - dep;
    if(dep == k) {
        int p = x - tot + 1;
        rep(i, 0, k) f[x][i] = p;
        f[x][a[p]] = tot + 1;
    print(x, ":");
    rep(i, 0, k) cerr << f[x][i] << " " ; cerr << endl;
        return;
    }
    int ls = (x << 1), rs = (x << 1 | 1);
    dfs(ls, dep + 1), dfs(rs, dep + 1);
    rep(i, 0, k) f[x][i] = 0;
    if(d[dep][x] == 0) {
        rep(i, 0, k) rep(j, 0, k) {
            chmax(f[x][get(i, j, lim)], min(f[ls][i], f[rs][j]));
        }
    } else {
        rep(i, 0, k) rep(j, 0, k) {
            chmax(f[x][get(j, i, lim)], min(f[ls][i], f[rs][j]));
        }
    }
    print(x, ":");
    rep(i, 0, k) cerr << f[x][i] << " " ; cerr << endl;
}
int getans(int y, int dep, int val) {
    int lim = k - dep;
    if(dep == -1) return tot + 1;
    int x = y / 2, ls = (x << 1), rs = (x << 1 | 1);
    int ans = tot + 1;
    if(y == rs) {
        if(d[dep][x] == 0) {
            ans = query(ls, lim - 1);
        } else {
            if(val < lim) return 0;
        }
    } else {
        if(d[dep][x] == 0) {
            if(val < lim) return 0;
        } else {
            ans = query(rs, lim - 1);
        }
    }
    return min(ans, getans(x, dep - 1, val));
}

ll ans[N], add[N];

void solve(int T) {
    rep(i, 0, 3) X[i] = read();
    rep(i, 1, tot) a[i] = min(b[i] ^ X[i % 4], k);
    
    rep(i, 0, tot + 1) add[i] = ans[i] = 0;
    
    dfs(1, 0);
    
    rep(i, 1, tot) {
        int l = i + 1, r = getans(i, k - 1, a[i]);
        print(i, l, r);
        if(l > r) continue;
        add[l] += i;
        add[r + 1] -= i;
    }
    rep(i, 1, tot) ans[i] = ans[i - 1] + add[i];
    ll res = 0;
    rep(i, 1, m) {
        res ^= i * ans[c[i]];
        cerr << ans[c[i]] << endl;
    }
    cout << res << endl;
    
}

int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    
    n = read(), m = read();
    while((1 << k) < n) k ++;
    tot = 1 << k;
    rep(i, 1, n) b[i] = read();
    rep(i, 1, m) c[i] = read();
    rep(i, 1, k) {
        int p = k - i, siz = 1 << (k - i);
        d[p].resize(siz + 1);
        scanf("%s", s + 1);
        rep(j, 1, siz) d[p][j] = s[j] - '0';
    }
    
    int Ts = read();
    rep(T, 1, Ts) solve(T);
}