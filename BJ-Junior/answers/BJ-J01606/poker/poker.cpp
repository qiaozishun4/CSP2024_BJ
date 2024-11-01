#include <bits/stdc++.h>

using i64 = long long;
auto& IG = std::ignore;

const i64 MAXK = 140;
int parse1[] = {' ', 'D', 'C', 'H', 'S'};
int parse2[] = {' ', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
i64 vis[MAXK][MAXK], n;

void solve(void) {
    std::cin >> n;
    for (i64 i = 1; i <= n; ++i) {
        char ch1 = ' ', ch2 = ' ';
        while (isspace(ch1)) std::cin >> ch1;
        while (isspace(ch2)) std::cin >> ch2;
        vis[(int) ch1][(int) ch2] = 1;
    }
    i64 ans = 0;
    for (i64 i = 1; i <= 4; ++i) {
        for (i64 j = 1; j <= 13; ++j) {
            if (!vis[parse1[i]][parse2[j]]) {
                ++ans;
            }
        }
    }
    std::cout << ans << '\n';
}

int main() {
    IG = freopen("poker.in", "r", stdin);
    IG = freopen("poker.out", "w", stdout);

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    solve();

    return 0;
}
