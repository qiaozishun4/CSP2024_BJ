#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

int st[10];
int t;

signed main () {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    st[0] = 6;
    st[1] = 2;
    st[2] = 5;
    st[3] = 5;
    st[4] = 4;
    st[5] = 5;
    st[6] = 6;
    st[7] = 3;
    st[8] = 7;
    st[9] = 6;

    cin >> t;

    while (t--) {
        int n;

        cin >> n;

        int flag = 0;

        for (int i = 1; i <= 9; i++) {
            if (n == st[i]) {
                cout << i<<endl;
                flag = 1;
                break;
            }
        }

        for (int i = 1; i <= 9; i++) {
            if (!flag) {
                for (int j = 0; j <= 9; j++) {
                    if (!flag) {
                        for (int x = 0; x <= 9; x++) {
                            if (st[i] + st[j] == n) {
                                cout << i <<j << endl;
                                flag = 1;
                                break;
                            }

                            if (st[i] + st[j] +st[x] == n) {
                                cout << i << j << x << endl;
                                flag = 1;
                                break;
                            }
                        }
                    } else {
                        break;
                    }
                }
            } else {
                break;
            }
        }

        if (!flag) {
           cout << -1 << endl;
        }
    }


    return 0;
}
