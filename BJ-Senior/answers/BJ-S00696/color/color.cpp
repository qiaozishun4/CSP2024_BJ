#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000010;

int n, a[N], vis[N];
int red[N], blue[N];
int color[N];

int ans;

vector<int> num;
vector<int> v[N];

int lowbit(int i) { return i & -i; }

void updateRed(int x, int k) {
    for (int i = x; i <= n; i+=lowbit(i)) red[i] += k;
}

void updateBlue(int x, int k) {
    for (int i = x; i <= n; i+=lowbit(i)) blue[i] += k;
}

int queryRed(int x) {
    if (x == 0) return 0;
    int sum = 0;
    for (int i = x; i > 0; i-=lowbit(i)) sum += red[i];
    return sum;
}

int queryBlue(int x) {
    if (x == 0) return 0;
    int sum = 0;
    for (int i = x; i > 0; i-=lowbit(i)) sum += blue[i];
    return sum;
}

void cal() {
    memset(red, 0, sizeof red);
    memset(blue, 0, sizeof blue);
    for (int x : num) {
        for (int i = 0; i < v[x].size(); i++) {
            if (color[x] == 2) {
                updateBlue(v[x][i], 1);
            } else {
                updateRed(v[x][i], 1);
            }
        }
    }
    int res = 0;
    for (int x : num) {
        for (int i = 0; i < v[x].size(); i++) {
            if (i > 0) {
                if (color[x] == 1) {
                    if (queryRed(v[x][i]) - queryRed(v[x][i-1]-1) == 2) {
                        res += x;
                    }
                } else {
                    if (queryBlue(v[x][i]) - queryBlue(v[x][i-1]-1) == 2) {
                        res += x;
                    }
                }
            }
        }
    }
    ans = max(ans, res);
}

void dfs(int u) {
    if (u == n + 1) {
        cal();
        return;
    }
    if (!color[a[u]]) {
        color[a[u]] = 1;
        dfs(u + 1);
        color[a[u]] = 2;
        dfs(u + 1);
        color[a[u]] = 0;
    } else {
        dfs(u + 1);
    }
}

void solve() {
    memset(color, 0, sizeof color);
    memset(vis, 0, sizeof vis);
    ans = 0;
    cin >> n;
    num.clear();
    //qing kong!!!
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (!vis[a[i]]) {
            vis[a[i]] = 1;
            num.push_back(a[i]);
            v[a[i]].clear();
        }
        v[a[i]].push_back(i);
    }
    dfs(1);
    cout << ans << '\n';
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}