#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n = 0, a[N] = { 0 };
int buc[N] = { 0 }, tot = 0;
int ans = 0, vis[N] = { 0 };

struct node{
    int x, c1, c2;
}p[N];

bool cmp(node x, node y) {
    return x.x < y.x;
}

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios :: sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        buc[a[i]]++;
        //cout << buc[a[i]] << ' ';
    }
    for (int i = 1; i < N; i++) {
        if (buc[i] && !vis[i]) {
            p[++tot] = {i, buc[i], buc[i]};
            vis[i] = 1;
        }
    }
    sort(p + 1, p + tot + 1, cmp);
    int l = 1, r = 2;
    bool fl = 0;
    while (l <= tot && r <= tot && !fl) {
        //cout << "11111111";
        //cout << l << ' ' << r << endl;
        //cout << p[l].c1 << ' ' << p[r].c1 << endl;
        //cout << p[l].c2 << ' ' << p[r].c2 << endl;
        while (1) {
            if (p[r].c2 < p[l].c1) {
                p[l].c1 -= p[r].c2;
                p[r].c2 = 0;
                if (r + 1 <= tot) r++;
                else {
                    fl = 1;
                    break;
                }
            } else {
                p[r].c2 -= p[l].c1;
                p[l].c1 = 0;
                if (l + 1 <= tot) l++;
                else fl = 1;
                if (l == r) {
                    if (r + 1 <= tot) r++;
                    else fl = 1;
                }
                break;
            }
        }
        if (r >= tot && l == tot) break;
        //cout << p[l].c1 << ' ' << p[r].c1 << endl;
        //cout << p[l].c2 << ' ' << p[r].c2 << endl;
    }
    for (int i = 1; i <= tot; i++) {
        ans += p[i].c1;
        //cout << p[i].c1 << ' ';
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0; 
}