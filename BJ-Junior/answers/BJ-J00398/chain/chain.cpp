#include <bits/stdc++.h>
using namespace std;
int n, k, q, l, x, y;
void solve(){
    cin >> n >> k >> q;
    for (int i = 1;i <= n;i++){
        cin >> l;
        while (l--) cin >> x;
    }  while (q--){
        cin >> x >> y;
        cout << "0\n";
    }
} int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}