#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, r[100010], ans;
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        r[tmp]++;
    }
    for(int i = 1; i < 100010; i++) ans = max(ans, r[i]);
    cout << ans << '\n';
    return 0;
}