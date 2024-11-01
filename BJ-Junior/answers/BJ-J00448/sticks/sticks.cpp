#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const long long int MAX_LLONG = 0xffffffff;

int t, n;
int a[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
ll ans;
//2 3 4 5 6 7

//      number       geshu
void dfs(ll k, ll p) {
    if (p == 1) {
        return;
    }
    if (p == 0) {
        ans = min(ans, k);
        //printf("k=%d\n", k);
        return;
    }

    for (int i = 0;i < 10;i++) {
        if (i == 0 and p == n)
            continue;
        if (p >= a[i]) {
            //printf("go %d\n", i);
            dfs(k * 10 + i, p - a[i]);
        }
    }
    return;
}


int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 7 == 0) {
            for (int i = 1;i <= n / 7;i++)
                cout << 8;
            cout << '\n';
            continue;
        }
        ans = MAX_LLONG;
        dfs(0, n);
        if (ans == MAX_LLONG)
            cout << "-1\n";
        else
            cout << ans << '\n';
    }
    return 0;
}

















