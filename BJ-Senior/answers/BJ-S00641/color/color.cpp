//BJ-S00641 color.cpp
//1 AC 2 TLE
//Locked
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n;
long long ans = 0;

int a[200005];
bool c[200005]; //is blue?

void dfs(int st) {
    if (st > n) {
        long long now = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 1; j--) {
                if (c[j] == c[i]) {
                    if (a[j] == a[i]) now += a[i];
                    break;
                }
            }
        }
        ans = max(ans, now);
        return;
    }
    c[st] = 0;
    dfs(st + 1);
    c[st] = 1;
    dfs(st + 1);
    return;
}

int main() {

    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    int TEST;
    cin >> TEST;
    while (TEST--) {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}

