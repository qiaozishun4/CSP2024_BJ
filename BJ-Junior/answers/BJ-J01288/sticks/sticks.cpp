include <bits/stdc++.h>
using namespace std;

const int num[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
long long ans = 1e17, n;

void dfs(int step, long long now, long long sum) {
    if (now == 0) {
        ans = min(ans, sum);
        return;
    }
    if (step == 0) {
        for (int i = 1; i <= 9; ++i) {
            if (now - num[i] >= 0)
                dfs(step + 1, now - num[i], sum * 10 + i);
        }
    }
    else {
        for (int i = 0; i <= 9; ++i) {
            if (now - num[i] >= 0)
                dfs(step + 1, now - num[i], sum * 10 + i);
        }
    }
}

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n <= 1) {
            cout << -1 << endl;
            continue;
        }
        if (n <= 7) {
            int minn = 1e9;
            for (int i = 1; i <= 9; ++i) {
                if (num[i] == n) minn = min(minn, i);
            }
            cout << minn << endl;
        }
        else if (n <= 29) {
            ans = 1e9;
            dfs(0, n, 0);
            cout << ans << endl;
        }
        else if (n % 7 == 0) {
            for (int i = 1; i <= n / 7; ++i) cout << 8;
            cout << endl;
        }
        else if ((n - 1) % 7 == 0) {
            cout << 10;
            for (int i = 1; i <= (n - 8) / 7; ++i) cout << 8;
            cout << endl;
        }
        else if ((n - 2) % 7 == 0) {
            cout << 1;
            for (int i = 1; i <= (n - 2) / 7; ++i) cout << 8;
            cout << endl;
        }
        else if ((n - 3) % 7 == 0) {
            cout << 200;
            for (int i = 1; i <= (n - 3) / 7 - 2; ++i) cout << 8;
            cout << endl;
        }
        else if ((n - 4) % 7 == 0) {
            cout << 20;
            for (int i = 1; i <= (n - 4) / 7 - 1; ++i) cout << 8;
            cout << endl;
        }
        else if ((n - 5) % 7 == 0) {
            cout << 2;
            for (int i = 1; i <= (n - 5) / 7; ++i) cout << 8;
            cout << endl;
        }
        else if ((n - 6) % 7 == 0) {
            cout << 6;
            for (int i = 1; i <= (n - 6) / 7; ++i) cout << 8;
            cout << endl;
        }
    }
    return 0;
}