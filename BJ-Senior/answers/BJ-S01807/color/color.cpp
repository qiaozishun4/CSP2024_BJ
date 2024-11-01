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

const int N = 1e6 + 10;

ll f[N], g[N];
bool vis[N];
int a[N];

inline void chmax(ll &x, ll y) { x = max(x, y); }

void solve(int T) {
    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);
    memset(vis, 0, sizeof vis);
    int n = read();
    rep(i, 1, n) a[i] = read();
    a[0] = 0;
    ll add = 0;
    // if(n > 5000) return;
    rep(i, 1, n) {
        if(a[i] == a[i - 1]) {
            add += a[i];
        } else {
            // ll mx = 0;
            if(vis[a[i]]) {
                chmax(f[i - 1], g[a[i]] + a[i]);
                // chmax(mx, f[j]);
            }
            // if(mx != g[a[i]]) print(mx, g[a[i]]);
            chmax(g[a[i - 1]], f[i - 1]);
        }
        f[i] = max(f[i], f[i - 1]);
        chmax(g[a[i]], f[i]);
        vis[a[i]] = 1;
    }
    cout << *max_element(f + 1, f + n + 1) + add << endl;
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    
    int Ts = read();
    rep(T, 1, Ts) solve(T);
    
}