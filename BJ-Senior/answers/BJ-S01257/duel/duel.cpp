#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int num[100005];
int gnum[100005];
int find_next(int x, int maxx) {
    for (int i = x+1; i <= maxx; i++) {
        if (num[i] != 0)  return i;
    }
    return 200005;
}
int gfind_next(int x, int maxx) {
    for (int i = x+1; i <= maxx; i++) {
        if (gnum[i] != 0)  return i;
    }
    return 200005;
}
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    int maxx = 0, minn = 200005, nxmin = 200005;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        num[a[i]]++;
        gnum[a[i]]++;
        maxx = max(maxx, a[i]);
        minn = min(minn, a[i]);
        if (minn != a[i])  nxmin = min(nxmin, a[i]);
    }
    while (minn != maxx && nxmin <= maxx) {
        num[minn] -= gnum[nxmin];
        gnum[nxmin] = 0 - num[minn];
        if (num[minn] <= 0) {
            minn = find_next(minn, maxx);
        }
        if (gnum[nxmin] <= 0 || minn == nxmin) {
            nxmin = gfind_next(nxmin, maxx);
        }
    }
    int ans = 0;
    for (int i = 1; i <= maxx; i++) {
        if (num[i] > 0)  ans += num[i];
    }
    cout << ans;
    return 0;
}