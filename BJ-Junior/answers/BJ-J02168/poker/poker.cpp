#include <bits/stdc++.h>

using namespace std;

const int N = 100;

bool p[N][N];

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, tt = 0;
    string s;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        p[(int)s[0]][(int)s[1]] = 1;
    }
    for (int i : {'D','C','H','S'}) {
        for (int j : {'A','2','3','4','5','6','7','8','9','T','J','Q','K'}) {
            if (!p[i][j]) {
                tt++;
            }
        }
    }
    cout << tt;
    return 0;
}
