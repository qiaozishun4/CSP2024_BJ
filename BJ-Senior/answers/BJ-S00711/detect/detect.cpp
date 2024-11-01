#define up(i, l, r) for(auto i = l; i <= r; ++i)
#define dn(i, r, l) for(auto i = r; i >= l; --i)
#define FILE_NAME "detect"

#include<bits/stdc++.h>

using namespace std;
using LL = long long;
using ULL = unsigned long long;

template<typename T>
inline void read(T &x) {
    char c = getchar();
    bool f = false;
    while(c <'0' || c > '9') {
        if(c == '-') {
            f = true;
        }
        c = getchar();
    }
    x = 0;
    while(c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    if(f) {
        x = 0 - x;
    }
}
template<typename T, typename ...Args>
inline void read(T &x, Args &...args) {
    read(x);
    read(args...);
}

const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;
const int MAXL = 1e6 + 5;
int T, n, m, L, V;

struct CAR {
    int d, v, a, l, r;
} c[MAXN];
int p[MAXM];

double delta(int v, int a) {
    if(a == 0) return L;
    return 1.0 * (V * V - v * v) / (2 * a);
}

struct TR {
    int a[MAXL], len;
    TR(int length):len(length), a({0}) {}
    void modify(int i, int x) {
        while(i <= len) {
            a[i] += x;
            i += i & (-i);
        }
    }
    int query(int i) {
        int sum = 0;
        while(i) {
            sum += a[i];
            i -= i & (-i);
        }
        return sum;
    }
};

int main() {
    #ifdef FILE_NAME
    freopen(FILE_NAME".in" , "r", stdin );
    freopen(FILE_NAME".out", "w", stdout);
    #endif // FILE_NAME
    read(T);
    up(_t, 1, T) {
        read(n, m, L, V);
        TR C(L + 2);
        up(i, 1, n) {
            read(c[i].d, c[i].v, c[i].a);
            c[i].l = c[i].r = L + 1;
            if(c[i].a < 0) {
                if(c[i].v > V) {
                    c[i].l = c[i].d;
                    c[i].r = c[i].d + (int)ceil(delta(c[i].v, c[i].a));
                    c[i].r = min(c[i].r, L + 1);
                    C.modify(c[i].l, 1);
                    C.modify(c[i].r, -1);
                }
            }
            else if (c[i].a == 0) {
                if(c[i].v > V) {
                    c[i].l = c[i].d;
                    c[i].r = L + 1;
                    C.modify(c[i].l, 1);
                    C.modify(c[i].r, -1);
                }
            }
            else {
                if(c[i].d + (int)ceil(delta(c[i].v, c[i].a)) <= L) {
                    c[i].l = c[i].d +int(delta(c[i].v, c[i].a) + 1);
                    c[i].r = L + 1;
                    C.modify(c[i].l, 1);
                    C.modify(c[i].r, -1);
                }
            }
        }
        //sort(c + 1, c + 1 + n, [](CAR xx, CAR yy) {
        //   return xx.l != yy.l ? xx.l < yy.l : xx.r < yy.r;
        //});
        TR S(L + 2);
        up(i, 1, m) {
            read(p[i]);
            S.modify(p[i], 1);
        }
        int tot = 0, ans = m;
        up(i, 1, n) {
            int left = S.query(c[i].l - 1),
                right = S.query(c[i].r - 1);
            if(right - left > 0) {
                ++tot;
                if(right - left == 1) --ans;
            }
        }
        printf("%d %d\n", tot, ans);
    }
    return 0;
}
