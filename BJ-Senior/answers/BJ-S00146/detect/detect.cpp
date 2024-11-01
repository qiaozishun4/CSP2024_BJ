#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int NMAX = 110000;
const int MMAX = 110000;

struct Car
{
    int d;
    int v;
    int a;
};

struct Segment
{
    int l;
    int r;
    bool operator<(const Segment &op) const {
        return r < op.r;
    }
};

int T;
int N, M, L, V;
Car car[NMAX];
int P[MMAX];
int n_seg;
Segment seg[NMAX];

bool check_speed(int c, int p)
{
    const Car &_c = car[c];
    if(_c.d > P[p])
        return false;
    int s = P[p] - _c.d;
    if(_c.a > 0) {
        return 1ll * _c.v * _c.v + 2ll * _c.a * s > 1ll * V * V;
    } else if(_c.a == 0) {
        return _c.v > V;
    } else {
        if(1ll * _c.v * _c.v < 2ll * (-_c.a) * s)
            return false;
        return 1ll * _c.v * _c.v + 2ll * _c.a * s > 1ll * V * V;
    }
}

bool is_too_high(int c)
{
    const Car &_c = car[c];
    if(_c.a > 0) {
        return check_speed(c, M);
    } else {
        int near_p = lower_bound(P + 1, P + M + 1, _c.d) - P;
        if(near_p > M)
            return false;
        return check_speed(c, near_p);
    }
}

Segment calc_segment(int c)
{
    const Car &_c = car[c];
    int near_p = lower_bound(P + 1, P + M + 1, _c.d) - P;
    int L, R;
    if(_c.a > 0) {
        // (]
        int l = near_p;
        int r = M;
        R = r;
        if(check_speed(c, l)) {
            L = l;
        } else {
            while(l + 1 < r) {
                int mid = (l + r)>>1;
                if(check_speed(c, mid)) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            L = r;
        }
    } else {
        // [)
        int l = near_p;
        int r = M;
        L = l;
        if(check_speed(c, r)) {
            R = r;
        } else {
            while(l + 1 < r) {
                int mid = (l + r)>>1;
                if(check_speed(c, mid)) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            R = l;
        }
    }
    return (Segment){L, R};
}

int solve()
{
    int ans = 0;
    sort(seg + 1, seg + n_seg + 1);
    /*
    for(int i = 1;i <= n_seg;i += 1) {
        printf("[%d, %d]\n", seg[i].l, seg[i].r);
    }
    */
    int last_choose = -1;
    int seg_idx = 1;
    for(int i = 1;i <= M;i += 1) {
        bool have_to = false;
        while(seg_idx <= n_seg && seg[seg_idx].r < i) {
            if(last_choose < 0 || seg[seg_idx].l > last_choose) {
                have_to = true;
            }
            seg_idx += 1;
        }
        if(have_to) {
            ans += 1;
            last_choose = i - 1;
            // printf("choose %d\n", i - 1);
        }
    }
    bool have_to = false;
    while(seg_idx <= n_seg) {
        if(last_choose < 0 || seg[seg_idx].l > last_choose) {
            have_to = true;
        }
        seg_idx += 1;
    }
    if(have_to)
        ans += 1;
    return M - ans;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%d", &T);
    for(int t = 1;t <= T;t += 1) {
        scanf("%d %d %d %d", &N, &M, &L, &V);
        for(int i = 1;i <= N;i += 1) {
            int d, v, a;
            scanf("%d %d %d", &d, &v, &a);
            car[i] = (Car){d, v, a};
        }
        for(int i = 1;i <= M;i += 1) {
            scanf("%d", &P[i]);
        }
        int n_high = 0;
        n_seg = 0;
        for(int i = 1;i <= N;i += 1) {
            if(is_too_high(i)) {
                seg[++n_seg] = calc_segment(i);
                n_high += 1;
            }
        }
        int n_min_keep = solve();
        printf("%d %d\n", n_high, n_min_keep);
    }
    exit(0);
}