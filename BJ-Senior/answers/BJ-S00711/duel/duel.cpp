#define up(i, l, r) for(auto i = l; i <= r; ++i)
#define dn(i, r, l) for(auto i = r; i >= l; --i)
#define FILE_NAME "duel"

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

const int MAXN = 1e5 + 1;
int n, r[MAXN], a[MAXN], s[MAXN], p;

int main() {
    #ifdef FILE_NAME
    freopen(FILE_NAME".in" , "r", stdin );
    freopen(FILE_NAME".out", "w", stdout);
    #endif
    read(n);
    up(i, 1, n) {
        read(r[i]);
    }
    sort(r + 1, r + 1 + n);
    up(i, 1, n) {
        if(r[i] != r[i - 1]) {
            a[++p]++;
            s[p] = s[p - 1] + 1;
        }
        else {
            a[p]++;
            s[p]++;
        }
    }
    int ans = n, left = 0;
    up(i, 1, p) {
        if(a[i] >= left) {
            ans -= left;
            left = a[i];
        }
        else {
            ans -= a[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
