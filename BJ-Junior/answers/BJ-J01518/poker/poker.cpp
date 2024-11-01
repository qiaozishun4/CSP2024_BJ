#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
int a[5][14];
char c[3];
int ans = 0;


signed main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    cin >> n;

    int hua = 0;
    int dian = 0;
    for (int i=1;i<=n;i++) {
        cin >> c;
        if (c[0] == 'D') hua = 1;
        else if (c[0] == 'C') hua = 2;
        else if (c[0] == 'H') hua = 3;
        else if (c[0] == 'S') hua = 4;

        if (c[1]-'0'>=1 && c[1]-'0'<=9) dian = c[1]-'0';
        else if (c[1] == 'A')dian = 1;
        else if (c[1] == 'T')dian = 10;
        else if (c[1] == 'J')dian = 11;
        else if (c[1] == 'Q')dian = 12;
        else if (c[1] == 'K')dian = 13;

        a[hua][dian] = 1;
    }

    for (int i=1;i<=4;i++) {
        for (int j=1;j<=13;j++) {
            if (a[i][j] == 0)ans++;
        }
    }

    cout << ans;

    return 0;
}
