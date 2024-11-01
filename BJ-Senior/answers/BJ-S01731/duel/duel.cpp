

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, t) for(int i = s; i <= t; i++) 
#define per(i, s, t) for(int i = t; i >= s; i--)

typedef long long ll;
typedef long double ldb;

const int MAXN = 1e5 + 9;

int n;
int a[MAXN];
int cnt[MAXN];
int res = 0;

int main () {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    cin >> n;

    rep (i, 1, n) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    rep (i, 1, 1e5) {
        res = max(res, cnt[i]);
    }
    
    cout << res << '\n';

    return 0;

}