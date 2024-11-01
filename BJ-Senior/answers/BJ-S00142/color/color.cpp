#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int T, n, ret;
int a[N], c[N], b[N];  //b数组，0为蓝， 1为红

void dfs(int u) {
    //cout << u << endl;

    if (u == n + 1) {
        int sum = 0;
        for (int i = 1; i <= n; i++)    sum += c[i];
        ret = max(ret, sum);
        return ;
    }

    b[u] = 0;
    for (int i = u - 1; i >= 1; i--) {
        if (a[i] == a[u] && b[i] == 0) {
            c[u] = a[i];
            break;
        }
    }

    dfs(u + 1);
    c[u] = 0;

    b[u] = 1;
    for (int i = u - 1; i >= 1; i--) {
        if (a[i] == a[u] && b[i] == 1) {
            c[u] = a[i];
            break;
        }
    }

    dfs(u + 1);
    c[u] = 0;
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++)    scanf("%d", &a[i]);

        memset(c, 0, sizeof c);
        memset(b, 0, sizeof b);
        ret = -0x3f;

        dfs(1);

        printf("%d\n", ret);
    }

    return 0;
}
