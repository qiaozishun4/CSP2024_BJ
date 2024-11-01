#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, a[200005];
long long ans, f[N][N];
long long check(int x) {
    long long ret = 0, lst1 = -1, lst2 = -1;
    for(int i = 0; i < n; ++i) {
        if((1 << i) & x) {
            if(lst1 == a[i + 1]) ret += lst1;
            else lst1 = a[i + 1];
        } else {
            if(lst2 == a[i + 1]) ret += lst2;
            else lst2 = a[i + 1];
        }
    }
    return ret;
}
long long dfs(int x, int y) {
    if(~f[x][y]) return f[x][y];
    f[x][y] = 0;
    if(y > x) {
        if(y > x + 1) f[x][y] = dfs(x, y - 1) + (a[y - 1] ^ a[y] ? 0 : a[y]);
        else {
            for(int i = x - 1; ~i; --i) {
                f[x][y] = max(dfs(x, i) + (a[i] ^ a[y] ? 0 : a[i]), f[x][y]);
            }
        }
    } else {
        if(x > y + 1) f[x][y] = dfs(x - 1, y) + (a[x - 1] ^ a[x] ? 0 : a[x]);
        else {
            for(int i = y - 1; ~i; --i) {
                f[x][y] = max(dfs(i, x) + (a[x] ^ a[i] ? 0 : a[x]), f[x][y]);
            }
        }
    }
    return f[x][y];
}
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        ans = 0;
        if(n <= 15) {
            for(int i = (1 << n) - 1; ~i; --i) ans = max(ans, check(i));
            printf("%lld\n", ans);
        } else if(n <= 2000) {
            memset(f, -1, sizeof(f));
            //cout << dfs(1, 2) << endl;
            for(int i = n - 1; ~i; --i) ans = max(ans, dfs(i, n));
            printf("%lld\n", ans);
        } else {
            srand(time(NULL));
            for(int i = int(1e7) / n; i; --i) {
                long long mem = 0;
                int lst1 = -1, lst2 = -1;
                for(int j = 1; j <= n; ++j) {
                    bool x = rand() % 2;
                    if(x) {
                        if(lst1 == a[j + 1]) mem += lst1;
                        else lst1 = a[j + 1];
                    } else {
                        if(lst2 == a[j + 1]) mem += lst2;
                        else lst2 = a[j + 1];
                    }
                }
                ans = max(ans, mem);
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}