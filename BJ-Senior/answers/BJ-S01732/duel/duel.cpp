#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5 + 10;
int box[NR];

inline int read() {
    char c; int op, x;
    c = getchar();

    if (c == '-') op = -1, x = 0;
    else op = 1, x = c - '0';

    c = getchar();
    while (c != '\n' && c != ' ') {
        x = x * 10 + c - '0';
        c = getchar();
    }

    return op * x;
}

inline void print(int x) {
    if (x < 0) x = -x, putchar('-');
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    int n = read();

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = read();
        ans = max(ans, ++box[x]);
    }

    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
