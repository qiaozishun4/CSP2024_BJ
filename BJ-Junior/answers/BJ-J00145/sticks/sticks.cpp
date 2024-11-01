#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
typedef long long ll;
int t, n;
int sn[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int dfs(int number, int le) {
    if (le < 0 || le == 1) {
        return -1;
    }
    if (le == 0) {
        return number;
    }
    ll ans = -1;
    for (int i = 0; i < 10; i++) {
        if (number == 0 && i == 0) {
            continue;
        }
        ll call = dfs((long long)(number * 10 + i), le - sn[i]);
        if (call < 0) {
            continue;
        }
        if (ans == -1) {
            ans = call;
        } else {
            ans = min(ans, call);
        }
    }
    return ans;
}
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        bool flag = false;
        for (int i = 1; i <= 20000; i++) {
            if (i * 7 == n) {
                for (int j = 1; j <= i; j++) {
                    printf("8");
                }
                cout << endl;
                flag = true;
                break;
            }
            if (i * 7 + 1 == n) {
                printf("10");
                for (int j = 1; j < i; j++) {
                    printf("8");
                }
                cout << endl;
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << dfs(0, n) << endl;
        }
    }
    return 0;
}
