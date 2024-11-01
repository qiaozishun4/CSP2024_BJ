#include <iostream>
#include <cstdio>
using namespace std;
const int N = 200015;
int a[N], n;
int clr[N];
int Cal(int id, int cl) {
    int ret = 0;
    clr[id] = cl;
    if ( id == n) {
        for ( int i = 1; i <= n; i++) {
            for ( int j = i - 1; j >= 1; j--) {
                if ( clr[j] == clr[i]) {
                    if ( a[i] == a[j]) {
                        ret += a[i];
                    }
                    break;
                }
            }
        }
        return ret;
    }
    ret = max(ret, Cal(id + 1, 0));
    ret = max(ret, Cal(id + 1, 1));
    return ret;
}
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    long long ans;
    while ( t--) {
        cin >> n;
        ans = 0;
        for ( int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        ans = Cal(1, 1);
        cout << ans << endl;
    }
    return 0;
}