#include <bits/stdc++.h>
using namespace std;
int t, n, k, p, l, a[1000005];
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> t;
    while(t--) {
        cin >> n >> k >> p;
        for(int i=1;i<=p;i++)
            cout << rand()%2 << '\n';
    }
    return 0;
}
