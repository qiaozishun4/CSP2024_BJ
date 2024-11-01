

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, t) for(int i = s; i <= t; i++) 
#define per(i, s, t) for(int i = t; i >= s; i--)

typedef long long ll;
typedef long double ldb;

const int MAXN = 2e5 + 9;
const int MAXM = 1e6 + 9;

int T;
int n;
int a[MAXN];
ll cnt[MAXM];

string IntToBinary (int x) {

    string res = " ";

    while (x) {
        res = (char) (x % 2 + '0') + res;
        x /= 2;
    }

    res = ' ' + res;

    return res;

}

int main () {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    cin >> T;

    while (T--) {
        ll res = 0;

        cin >> n;

        if (n <= 15) {
            rep (i, 1, n) {
                cin >> a[i];
            }

            rep (k, 0, (1 << n) - 1) {
                string s = IntToBinary(k);
                ll ans = 0;

                rep (i, 1, n) {
                    per (j, 1, i - 1) {
                        if (s[i] == s[j]) {
                            if (a[i] == a[j]) {
                                ans += a[i];
                            }

                            break;
                        }
                    }
                }

                res = max(res, ans);
            }

            cout << res << '\n';

            continue;
        }

        memset(cnt, 0, sizeof(cnt));

        rep (i, 1, n) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        rep (i, 1, 1e6) {
            if (cnt[i]) {
                res += (cnt[i] - 1) * i;
            }
        }

        cout << res << '\n';
    }
    
    return 0;

}