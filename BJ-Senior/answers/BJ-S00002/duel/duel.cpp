#include <bits/stdc++.h>
using namespace std;
const int N = 1E5 + 5;
int a[N];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int minn = 1;
    int ans = n;
    for(int i = 2; i <= n; i++) {
        if(a[i] > a[minn]) {
            ans--;
            minn++;
        }
    }
    cout << ans;
    return 0;
}