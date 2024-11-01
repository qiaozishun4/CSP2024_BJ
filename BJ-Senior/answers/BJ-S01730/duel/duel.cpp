#include<bits/stdc++.h>
using namespace std;

unsigned int n, i;
unsigned int m1[(size_t)1e5], m2[(size_t)1e5];

int x = 1e5, y;
static inline void next_x() noexcept {
    while((++x)!=1e5 && m1[x]==0);
}
static inline void next_y() noexcept {
    while((++y)!=1e5 && m2[y]==0);
}

int main() noexcept {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%u", &n);
    for(unsigned int r;i<n;++i){
        scanf("%u", &r);
        ++m1[r];
        ++m2[r];
        x = min<int>(x, r);
    }
    y = x;
    next_y();
    while (y!=1e5 && x!=1e5) {
        i = min(m1[x], m2[y]);
        if ((m2[y] -= i) == 0) {
            next_y();
        }
        if (m1[x] == i) {
            next_x();
            if (x == y) { next_y(); }
        } else {
            m1[x] -= i;
        }
        n -= i;
    }
    printf("%d", n);
    fclose(stdin);
    fclose(stdout);
    return 0;
}