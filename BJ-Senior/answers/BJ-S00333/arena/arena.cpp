#include <iostream>
using namespace std;

int n, m, k, T;
int a[100005], c[100005];
int cnt, cur, x[4];
int ansA, ansB;
char d[30][100005];

struct player {
    int a, id;
}p[100005];

int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> c[i];
    for (int i = 1; i < 30; i++)
        if ((1<<i)>=n) {
            k = i;
            break;
        }
    for (int r = 1; r <= k; r++)
        for (int g = 1; g <= (1<<k-r); g++)
            cin >> d[r][g];
    cin >> T;
    while (T--) {
        ansA = 0;
        for (int i = 1; i <= 4; i++)
            cin >> x[i];
        for (int t = 1; t <= m; t++) {
            for (int i = 1; i <= c[t]; i++)
                p[i] = player{a[i]^x[i%4], i};
            cnt = c[t];
            for (int r = 1; ; r++) {
                cur = 0;
                if (cnt == 1)
                    break;
                for (int i = 1; i <= cnt-1; i += 2)  {
                    player holder = (d[r][i+1>>1] == '0')?p[i]:p[i+1];
                    player another = (holder.id == p[i].id)?p[i+1]:p[i];
                    if (holder.a >= r)
                        p[++cur] = holder;
                    else
                        p[++cur] = another;
                }
                cnt = cur;
            }
            ansA ^= p[1].id*t;
        }
        cout << ansA << endl;
    }
    return 0;
}