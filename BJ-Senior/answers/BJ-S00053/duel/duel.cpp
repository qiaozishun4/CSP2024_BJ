#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, r[N], tmp[N], t[N], minsum, ans;
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> r[i];
        tmp[i] = r[i];
    }
    sort(tmp+1, tmp+1+n);
    int num = unique(tmp+1, tmp+1+n)-tmp-1;
    for(int i = 1; i <= n; i++) {
        r[i] = lower_bound(tmp+1, tmp+1+num, r[i]) - tmp;
        t[r[i]]++;
    }
    for(int i = 1; i <= num; i++) {
        if (t[i] > minsum) {
            ans += t[i]-minsum;
            minsum = t[i];
        }
//        cout << i << " " << minsum << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
