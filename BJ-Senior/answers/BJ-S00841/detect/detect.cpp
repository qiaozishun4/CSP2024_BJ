#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int T, n, m, L, V, ans, ans1, ans2;
int p[MAXN];
int use[MAXN][2];

struct node{
    int l, r;
    node() {
        l = 0;
        r = 0;
    }
    bool operator<(const node&b) const{
    if (this->r != b.r) {
        return this->r < b.r;
    } else {
        return this->l < b.l;
    }
}    
}seg[MAXN];


int bi_max(int l, int r, int fi) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (p[mid] < fi) {
        return bi_max(mid + 1, r, fi);
    } else {
        return bi_max(l, mid, fi);
    }
}


int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%d", &T);
    while(T--) {
        ans = 0;
        ans1 = 0;
        ans2 = 0;
        scanf("%d %d %d %d", &n, &m, &L, &V);
        for (int i = 1; i <= n; i++) {
            int d, v, a;
            scanf("%d %d %d", &d, &v, &a);
            if (a == 0) {
                if (v <= V) {
                    continue;
                } else {
                    use[++ans][0] = d;
                    use[ans][1] = L;
                }
            } else if (a <= 0) {
                if (v <= V) {
                    continue;
                } else {
                    int temp;
                    double use1 = ((double)v * (double)v - (double)V * (double)V) / ((double)-a * 2.0);
                    if (use1 == (int)use1) {
                        temp = (int)use1 - 1;
                    } else {
                        temp = (int)use1;
                    }
                    if (temp + d > L) {
                        use[++ans][0] = d;
                        use[ans][1] = L;
                    } else {
                        use[++ans][0] = d;
                        use[ans][1] = d + temp;
                    }
                }
            } else {
                if (v >= V) {
                    use[++ans][0] = d;
                    use[ans][1] = L;
                } else {
                    double use1 = ((double)V * (double)V - (double)v * (double)v) / ((double)a * 2.0);
                    int temp;
                        temp = (int)use1 + 1;
                    if (d + temp > L) {
                        continue;
                    } else {
                        use[++ans][0] = d + temp;
                        use[ans][1] = L;
                    }
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &p[i]);
        }

        for (int i = 1; i <= ans; i++) {
            int l = bi_max(1, m, use[i][0]);
            int r = bi_max(1, m, use[i][1]);

            if (p[r] != use[i][1] && !(r == m && use[i][1] > p[m])) {
                r--;
            }
            
            if (l <= r && !(l == m && use[i][0] > p[m])) {
                seg[++ans1].l = l;
                seg[ans1].r = r;
            }
        }

        sort(seg + 1, seg + ans1 + 1);
        int temp1 = 0;
        for (int i = 1; i <= ans1; i++) {
            if (seg[i].l <= temp1) {
                continue;
            } else {
                temp1 = seg[i].r;
                ans2++;
            }
        }
        printf("%d %d\n", ans1, m - ans2);
    }
    return 0;
}