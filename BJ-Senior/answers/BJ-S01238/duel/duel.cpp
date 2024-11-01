#include <bits/stdc++.h>
using namespace std;
int n,a[100005],mx,f[100005];
int main () {
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int x;
        cin >> x;
        a[x]++;
        mx = max(mx,x);
    }
    f[0] = 0;
    for (int i = 1;i <= mx;i++) {
        if (a[i] > f[i - 1]) {
            f[i] = a[i];
        } else {
            f[i] = f[i - 1];
        }
    }
    cout << f[mx] << endl;
    return 0;
}