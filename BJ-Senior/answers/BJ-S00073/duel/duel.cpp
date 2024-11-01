#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N = 1E5 + 10;

int n, nn, ans;
int a[N], cnt[N];

signed main() {

    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);

    for(int i = 1; i <= n; i++) {
        if(a[i] != a[i - 1]) ++nn;
        cnt[nn]++;
    }

    for(int i = 1; i <= nn; i++) {
        ans = max(ans, cnt[i]);
    }

    cout << ans << endl;

    return 0;
}