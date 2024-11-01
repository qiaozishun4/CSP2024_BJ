// By Pr_159
// Sugar_Pigeon & 159 rp++!
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1e5 + 5;

struct Seg {
    LL l, r;
};

int T, n, m, L, d[N], p[N];
LL V, v[N], a[N];

bool cmp(Seg X, Seg Y) {
    if(X.l != Y.l) {
        return X.l < Y.l;
    }
    return X.r < Y.r;
}

bool cmp2(Seg X, Seg Y) {
    if(X.l != Y.l) {
        return X.l < Y.l;
    }
    return X.r > Y.r;
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T--) {
        bool subtask = 1;
        cin >> n >> m >> L >> V;
        for(int i = 1; i <= n; ++i) {
            cin >> d[i] >> v[i] >> a[i];
            if(a[i] < 0) {
                subtask = 0;
            }
        }
        for(int i = 1; i <= m; ++i) {
            cin >> p[i];
        }
        vector<Seg> S;
        for(int i = 1; i <= n; ++i) {
            if(a[i] == 0) {
                if(v[i] > V) {
                    S.push_back({d[i], L});
                }
            } else if(a[i] > 0) {
                if(v[i] > V) {
                    S.push_back({d[i], L});
                    continue;
                }
                LL s = d[i] + (V * V - v[i] * v[i]) / (2 * a[i]) + 1;
                if(s > L) {
                    continue;
                }
                S.push_back({s, L});
            } else {
                if(V > v[i]) {
                    continue;
                }
                LL s = d[i] + ceil((V * V - v[i] * v[i]) / (2 * a[i])) - 1;
                if(d[i] > s) {
                    continue;
                }
                S.push_back({d[i], s});
            }
        }
        sort(S.begin(), S.end(), cmp);
        int sum = 0, ans = 0;
        for(int i = 1, arr = 0; i <= m; ++i) {
            while(arr < S.size() && S[arr].r < p[i]) {
                ++arr;
            }
            while(arr < S.size() && S[arr].l <= p[i] && p[i] <= S[arr].r) {
                ++sum, ++arr;
            }
        }
        cout << sum << ' ';
        if(subtask) {
            if(sum) {
                cout << m - 1 << '\n';
            } else {
                cout << m << '\n';
            }
            continue;
        }
        vector<Seg> A;
        for(int i = 1, arr = 0, l, r; i <= m; ++i) {
            while(arr < S.size() && S[arr].r < p[i]) {
                ++arr;
            }
            bool flag = 0;
            if(arr < S.size() && S[arr].l <= p[i] && p[i] <= S[arr].r) {
                l = arr;
                flag = 1;
            }
            while(arr < S.size() && S[arr].l <= p[i] && p[i] <= S[arr].r) {
                ++arr;
            }
            r = arr - 1;
            if(flag) {
                A.push_back({l, r});
            } else {
                ++ans;
            }
        }
        sort(A.begin(), A.end(), cmp2);
        int cr = A[0].r, cur = cr;
        for(int i = 1; i < A.size(); ++i) {
            if(A[i].l > cur) {
                cr = A[i].r;
                cur = cr;
                continue;
            }
            if(A[i].r <= cr) {
                ++ans;
            } else {
                if(A[i].r > cur) {
                    cur = A[i].r;
                    if(cur != INT_MIN) ++ans;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
