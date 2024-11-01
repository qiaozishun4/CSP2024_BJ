#include <bits/stdc++.h>
using namespace std;

int a[100], Max = 0;
bool b[100];
int T, n, in;
void dfs(int x) {
    if (x == n + 1) {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        for (int j = i - 1; j > 0; j--) {
            if (b[i] == b[j]) {
                if (a[i] == a[j])
                    sum += a[i];
                    break;
            }
        }
        Max = max(sum, Max);
        return;
    }
    b[x] = 1;
    dfs(x + 1);
    b[x] = 0;
    dfs(x + 1);
    return;
}
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    while (T--) {
        Max = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        dfs(1);
        cout << Max << endl;
    }
    return 0;
}
