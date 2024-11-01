#include <bits/stdc++.h>
using namespace std;

int t, n, k, q;
int l[1005], r, c;
int s[2005][2005], ans;

void dfs(int cnt, int start) {
    if (cnt > r) {
        ans = max(ans, (int)(start == c));
    }
    for (int i = 1;i <= l[cnt];i++) {
        if (s[cnt][i] != start)
            continue;
        for (int j = i;j <= min(l[cnt], i+k);j++) {
            dfs(cnt + 1, s[cnt][j]);
            //cout << "//" << s[cnt][j] << "\n";
        }
    }
}

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> t;
    while (t--) {

        cin >> n >> k >> q;

        for (int i = 1;i <= n;i++) {
            cin >> l[i];
            for (int j = 1;j <= l[i];j++) {
                cin >> s[i][j];
            }
        }

        /*for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= l[i];j++) {
                cout << s[i][j];
            }
            cout << '\n';
        }*/


        while (q--) {
            cin >> r >> c;
            ans = 0;
            dfs(1, 1);
            cout << ans << "\n";
        }
    }
    return 0;
}
















