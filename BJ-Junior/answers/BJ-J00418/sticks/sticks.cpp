#include <iostream>
using namespace std;

int T, n;
int v[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int ans;

void dfs(int p, int w, int s) {
    if (s > ans)
        return;
    if (w == 0)
        ans = s;
    for (int i = (p==0)?1:0; i <= 9; i++) {
        if (v[i] > w)
            continue;
        dfs(p+1, w-v[i], s*10+i);
    }
}

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    while (T--) {
        ans = 2e9;
        cin >> n;
        dfs(0, n, 0);
        if (ans == 2e9)
            ans = -1;
        cout << ans << endl;
    }
    return 0;
}
