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

const int N = 3e5 + 10, K = 2e6 + 10;

// typedef double db;
// const db eps = 1e-3, eps2 = 1e-5;

ll d[N], v[N], a[N], p[N];
int _s[K], *s = _s + 2;
bool ok[N];

typedef pair<ll, ll> pii;

bool cmp(const pii &a, const pii &b) {
    return a.second < b.second;
}

int check(int l, int r) { return s[r] - s[l - 1]; }

void solve(int T) {
    memset(_s, 0, sizeof _s);
    int n = read(), m = read(); ll l = read()* 1, lim = read()* 1;
    int cnt1 = 0, cnt2 = 0;
    vector<pii> vec;
    rep(i, 1, n) {
        d[i] = read()* 1, v[i] = read()* 1, a[i] = read()* 1;
    }
    rep(i, 1, m) p[i] = read()* 1, s[p[i]] ++;
    // if(T != 1) return;
    // rep(i, 1, m) cerr << p[i] << " "; cerr << endl;
    rep(i, 0, K - 2) s[i] += s[i - 1];
    rep(i, 1, n) {
        // print(i, d[i], v[i], a[i]);
        if(a[i] > 0) {
            if(v[i] <= lim) {
                d[i] += (lim * lim - v[i] * v[i]) / (a[i] + a[i]) + 1;
            }
            if(d[i] > l) ok[i] = 1;
            else {
                vec.push_back({d[i], l});
            }
        } else {
            // print("OK");
            if(v[i] <= lim) ok[i] = 1;
            else {
                ll x = l;
                if(a[i] < 0) x = d[i] + (v[i] * v[i] - lim * lim - 1) / (-a[i] - a[i]);
                // if(i == 5) print("OK", d[i], min(x, l));
                vec.push_back({d[i], min(x, l)});
            }
        }
    }
    sort(vec.begin(), vec.end(), cmp);
    sort(p + 1, p + m + 1);
    p[m + 1] = l + 1;
    p[0] = -1; int top = 0;
    ll last = -1;
    for(auto &pr : vec) {
        ll l = pr.first, r = pr.second;
        // print(l, r, check(l, r));
        if(!check(l, r)) continue;
        // print("ok");
        cnt1 ++;
        if(l <= last) continue; 
        // print("OK");
        while(p[top + 1] <= r) top ++;
        last = p[top];
        cnt2 ++;
        // print(p[top]);
    }
    // print("OK");
    
    cout << cnt1 << " " << m - cnt2 << endl;
    // rep(i, 1, n) print(ok[i]);
    rep(i, 1, n) ok[i] = 0;
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    
    // print((595 * 595 - 247 * 247) / 11 / 2);
    
    int Ts = read();
    rep(T, 1, Ts) solve(T);
}