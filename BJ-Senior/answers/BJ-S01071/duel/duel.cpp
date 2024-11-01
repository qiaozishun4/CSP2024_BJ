#include <bits/stdc++.h>
using namespace std;
int a[100005], maxn = 0;
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        maxn = max(maxn, ++a[x]);
    }
    cout << maxn;
    return 0;
}
