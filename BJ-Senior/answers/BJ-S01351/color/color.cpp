#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int t, n, a[N];
int ans = 0;
vector <int> v;

void dfs(int x) {
    if (x == n) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (v[i] == v[j] && a[i] != a[j]) break;
                if ((v[i] == v[j]) && (a[i] == a[j])) {
                    //cout << a[i] << ' ' << a[j] << ' ' << j << ' ';
                    res += a[i];
                    //cout << i << ' ';
                    break;
                }
            }
        }
        //cout << res << endl;
        //cout << endl;
        ans = max(ans, res);
        return ;
    }
    v.push_back(1);
    dfs(x + 1);
    v.pop_back();
    v.push_back(0);
    dfs(x + 1);
    v.pop_back();
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        v.clear();
        dfs(0);
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}