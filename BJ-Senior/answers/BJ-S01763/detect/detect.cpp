#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LL __int128
#define lb(i) lower_bound(p+1, p+1+m, i)
#define ub(i) upper_bound(p+1, p+1+m, i)

const int N = 1e5 + 5;
const double eps = 1e-8;
int T, n, m, L, V, p[N];

struct speedUp {
    int l, r;
} a[N], b[N];

bool Up(int pos, int st, int add) { //判断是否超速
    if(st > V) return true;         // 初始速度就大了
    if(add <= 0) return false;      // 不增大
    double dis = L - pos;           // 走的距离
    double lasv = sqrt(1ll * st * st + 2 * add * dis);
    if(lasv - eps > V) return true; // 超了
    return false;
}

bool cmp(speedUp a, speedUp b) {
    if(a.r != b.r) return a.r < b.r;
    return a.l > b.l;
}

int check(int res) {
    int sum = 0, las = 1;
    for(int i = 1; i <= res; i++) {
        if(sum && b[i].l <= p[las] && p[las] <= b[i].r) continue;
        while(b[i].l > p[las]) las++;
        while(b[i].l <= p[las+1] && p[las+1] <= b[i].r && las < m) las++;
        sum++;
 //       printf("las = %d, i = %d\n", las, i);
    }
    return sum;
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%d", &T);
    while(T--) {
//        输入+判断是否不会超速

        int cnt = 0, res = 0;
        scanf("%d%d%d%d", &n, &m, &L, &V);

        for(int i = 1; i <= n; i++) {
            int pos, st, add, ok = 1;
            scanf("%d%d%d", &pos, &st, &add);
            if(!Up(pos, st, add)) continue;
            if(!add || (V * V - st * st) % (2 * add) == 0) ok = 0;

 //           printf("%d超了\n", i);

            if(st > V && add >= 0) {
                a[++cnt].l = pos;
                a[cnt].r = L;
            }

            else if(st > V && add < 0) {
                a[++cnt].l = pos;
                if(ok == 0) a[cnt].r = (V * V - st * st) / (2 * add) + pos - 1;
                else a[cnt].r = pos + floor((1.0 * (V * V - st * st) / (2 * add) + eps));
            }

            else {
                if(ok == 0) a[++cnt].l = (V * V - st * st) / (2 * add) + pos + 1;
                else a[++cnt].l = pos + ceil(1.0 * (V * V - st * st) / (2 * add) - eps);
                a[cnt].r = L;
            }

//            printf("%d : l = %d, r = %d\n", i, a[cnt].l, a[cnt].r);
        }

        for(int i = 1; i <= m; i++) scanf("%d", &p[i]);

//        计算有多少个会被判超速
        int ans = 0;
        for(int i = 1; i <= cnt; i++) {
            if(a[i].r == L) {
                if(p[m] >= a[i].l) ans++, b[++res] = a[i];
            }
            else {
                if(p[m] >= a[i].l) {
                    int pos = lb(a[i].l)-p;
                    if(p[pos] <= a[i].r) ans++, b[++res] = a[i];
                }
            }
//            printf("%d ", ans);
        }

        printf("%d ", ans);
//        排序，然后二分答案

        sort(b+1, b+1+res, cmp);
 //       for(int i = 1; i <= res; i++) printf("%d ~ %d\n", b[i].l, b[i].r);

        printf("%d\n", m-check(res));

    }
    return 0;
}

