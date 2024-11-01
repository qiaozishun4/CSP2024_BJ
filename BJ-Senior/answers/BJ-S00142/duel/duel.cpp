#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, cnt, cnt1, cnt2, idx;
int r[N], f[N], g[N], k[N];
bool vis[N];

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    cin >> n;
    bool flagg = true;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &r[i]);
        if (r[i] > 2)   flagg = false;
        if (r[i] == 1)  cnt1++;
        if (r[i] == 2)  cnt2++;
    }

    sort(r + 1, r + n + 1);

    if (n == 2) {
        if (r[1] != r[2])   cout << 1;
        else    cout << 2;
        return 0;
    }

    if (flagg) {
        cout << cnt2 + max(0, cnt1 - cnt2);
        return 0;
    }

    int cntt = 0;

    for (int i = 2; i <= n; i++) { //实现每种攻击力有几个
        if (i == 2) {
            if (r[2] == r[1]) {
                cntt = 2;
                continue;
            }
            f[++idx] = 1;
            cntt = 1;
            continue;
        }

        if (i == n) {
            if (r[i] == r[i - 1]) {
                f[++idx] = cntt + 1;
                break;
            }
            else {
                f[++idx] = cntt;
                f[++idx] = 1;
                break;
            }
        }

        if (r[i] == r[i - 1]) cntt++;
        else {
            f[++idx] = cntt;
            cntt = 1;
        }
    }

    for (int i = 2; i <= idx; i++) {
        g[i] = f[i - 1] + g[i - 1];
    }

    for (int i = 2; i <= idx; i++) {
        k[i] += k[i - 1] + g[i - 1];
        g[i] -= k[i];
        g[i] = min(g[i], f[i]);
        cnt += g[i];
    }

    cout << n - cnt;
    return 0;
}
