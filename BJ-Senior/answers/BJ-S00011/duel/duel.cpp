#include <bits/stdc++.h>

using namespace std;

inline int read() {
    int x = 0, w = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') w = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + ch - '0'; ch = getchar(); }
    return x * w;
}

int n;
int r[100005];
int a[100005];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    n = read();

    for (int i = 0; i < n; i++) {
        r[i] = read();
        a[r[i]]++;
    }

    sort(a + 1, a + 100001, cmp);

    cout << a[1] << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
