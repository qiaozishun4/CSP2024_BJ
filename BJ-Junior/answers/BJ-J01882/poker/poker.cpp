#include <bits/stdc++.h>
// long long freopen
using namespace std;
int const N = 1e5 + 10;
int n, a[N][5];
int main() {
    freopen("poker.in","r", stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;++i){
        string s;
        cin >> s;
        string t = "DCHS";
        if (s[1] == 'T') a[10][t.find(s[0])] ++;
        else if (s[1] == 'J') a[11][t.find(s[0])] ++;
        else if (s[1] == 'Q') a[12][t.find(s[0])] ++;
        else if (s[1] == 'K') a[13][t.find(s[0])] ++;
        else if (s[1] == 'A') a[1][t.find(s[0])] ++;
        else a[s[1]- '0'][t.find(s[0])]++;
    }
    int ans = 0;
    for (int i = 1;i <= 13;++i) {
        for (int j = 0;j <= 3;++j){
            if (a[i][j] == 0) ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}

