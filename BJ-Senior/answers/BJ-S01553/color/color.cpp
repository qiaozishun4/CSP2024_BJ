#include <bits/stdc++.h>
using namespace std;

int const N = 1e5 + 10;
int n, a[N], tot;
vector<int> c;

void dfs(int x){
    if (x == 0){
        int ans = 0;
        for (int i = 2;i <= n;++i) {
            for (int j = i - 1;j >= 1;--j) {
                if (c[i - 1] == c[j - 1]){
                    if (a[i] == a[j]) ans += a[i];
                    break;
                }
            }
        }
        /*
        if (ans > tot) {
            for (int i = 0;i < n;++i){
                cout << c[i];
            }
            cout << endl;
        }
        */
        tot = max(ans, tot);
        return;

    }
    c.push_back(0);
    dfs(x - 1);
    c.pop_back();
    c.push_back(1);
    dfs(x - 1);
    c.pop_back();
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        tot = 0;
        cin >> n;
        for (int i = 1;i <= n;++i) cin >> a[i];
        dfs(n);
        cout << tot << endl;
    }
    return 0;
}
