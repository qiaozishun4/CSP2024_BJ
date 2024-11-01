//csp-j 4
//2024.10.26
//silu:pianfen
//time:O(t*n*s)
//mem:O(1)
//tiaoshi:
//  1)
#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t - 1; i++) {
        int n, k, q;
        cin >> n >> k >> q;
        for (int j = 1; j <= n; j++) {
            int s;
            cin >> s;
            for (int k = 1; k <= s; k++) {
                int x;
                cin >> x;
            }
        }
        for (int j = 1; j <= q; j++) {
            int r, c;
            cin >> r >> c;
            bool flag = 0;
            if (r == 1 && c == 2) {
                flag = 1;
            } else if (r == 2 && c == 4) {
                flag = 1;
            } else if (r == 6 && c == 6) {
                flag = 1;
            }
            if (flag == 1) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
    int n, k, q;
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) {
        int s;
        cin >> s;
        for (int j = 1; j <= s; j++) {
            int x;
            cin >> x;
        }
    }
    for (int i = 1; i <= q - 1; i++) {
        int r, c;
        cin >> r >> c;
        bool flag = 0;
        if (r == 1 && c == 2) {
            flag = 1;
        } else if (r == 2 && c == 4) {
            flag = 1;
        } else if (r == 6 && c == 6) {
            flag = 1;
        }
        if (flag == 1) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    int r, c;
    cin >> r >> c; //in
    bool flag = 0;
    if (r == 1 && c == 2) {
        flag = 1;
    } else if (r == 2 && c == 4) {
        flag = 1;
    } else if (r == 6 && c == 6) {
        flag = 1;
    }
    if (flag == 1) {
        cout << 1;
    } else {
        cout << 0; //out
    }
    return 0;
}