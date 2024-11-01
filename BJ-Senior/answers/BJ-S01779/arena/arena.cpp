#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, aa[N], c[N], a[N], x[4], dep, cnt, xx;
vector<bool> d[20];
long long ans[N], out;
int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    int num = 1;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", aa + i);
    for(int i = 1; i <= m; ++i) {
        scanf("%d", c + i);
    }
    int nn = n;
    while(nn) {
        ++dep;
        nn >>= 1;
    }
    for(int i = dep; i; --i) {
        for(int j = (1 << dep - i); j; ) {
            char c = getchar();
            if(c == '1') {
                --j;
                d[i].push_back(1);
            } else if(c == '0') {
                --j;
                d[i].push_back(0);
            }
        }
    }
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d", x, x + 1, x + 2, x + 3);
        for(int i = n; i; --i) a[i] = aa[i] ^ x[i % 4];
        out = 0;
        for(int i = 1; i <= m; ++i) {
            if(c[i] == 1) out += 1 * i;
            else if(c[i] == 2) out += (d[1][1] ? (a[2] > 1 ? 2 : 1) : (a[1] > 1 ? 1 : 2)) * i;
            else if(c[i] == 3) {
                int win1 = d[2][1] ? (a[2] > 1 ? 2 : 1) : (a[1] > 1 ? 1 : 2);
                if(d[2][2]) {
                    if(d[1][1]) out += 4 * i + win1 * i + 3 * i;
                    else out += a[win1] > 2 ? win1 * i : 4 * i + 3 * i;
                } else {
                    int win2 = a[3] > 1 ? 3 : 4;
                    out += d[1][1] ? (a[win2] > 2 ? win2 * i : win1 * i) : (a[win1] > 2 ? win1 * i : win2 * i);
                }
            } else if(c[i] == 4) {
                int win1 = d[2][1] ? (a[2] > 1 ? 2 : 1) : (a[1] > 1 ? 1 : 2), win2 = d[2][2] ? (a[4] > 1 ?  : 4) : (a[3] > 1 ? 3 : 4);
                out += d[1][1] ? (a[win2] > 2 ? win2 * i : win1 * i) : (a[win1] > 2 ? win1 * i : win2 * i);
            }
        }
        printf("%lld\n", out);
    }
    return 0;
}