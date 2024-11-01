#include <bits/stdc++.h>
using namespace std;
int T, n;
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> n;
        if (n % 7 == 0)
            for (int i = 1; i <= (n / 7); i++)
                cout << 8;
        else if (n % 7 == 1) {
            if (n < 15)
                if (n == 8)
                    cout << 10;
                else
                    cout << -1 << endl;
            else {
                cout << 108;
                n -= 15;
                for (int i = 1; i <= (n / 7); i++)
                    cout << 8;
            }
        } else
            if (n == 2)
                cout << 1;
            else if (n == 3)
                cout << 7;
            else if (n == 4)
                cout << 4;
            else if (n == 5)
                cout << 2;
            else if (n == 6)
                cout << 6;
            else if (n == 9)
                cout << 18;
            else if (n == 10)
                cout << 22;
            else if (n == 11)
                cout << 26;
            else if (n == 12)
                cout << 28;
            else if (n == 13)
                cout << 68;
            else if (n == 16)
                cout << 188;
            else if (n == 17)
                cout << 206;
            else if (n == 18)
                cout << 208;
            else if (n == 19)
                cout << 288;
            else if (n == 20)
                cout << 688;
            else
                cout << -1;
        cout << endl;
    }
    return 0;
}
/*
10
1
8
15
22
29
7
14
21
28
35

-1
10
108
1088
10888
8
88
888
8888
88888
*/
