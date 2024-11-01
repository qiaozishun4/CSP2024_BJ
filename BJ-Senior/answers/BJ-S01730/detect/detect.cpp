#include<bits/stdc++.h>
using namespace std;
unsigned short T,V,V2;
unsigned int n,m,L, i, ans;
int j, k, idx;

struct Car {
    unsigned int d;
    short v, a;
} car[(size_t)1e5];

unsigned int p[(size_t)1e6];
bitset<(size_t)1e6> flags;

static inline void set_nearby(const unsigned int& d) noexcept {
    ++ans, flags[lower_bound(p, p+m, d) - p] = 1;
}

int main() noexcept {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%hu", &T);
    do {
        ans = 0, flags = 0;
        scanf("%u%u%u%hu", &n, &m, &L, &V);
        V2 = V*V;
        for(i=0;i<n;++i){ scanf("%u%hd%hd", &car[i].d, &car[i].v, &car[i].a); }
        for(i=0;i<m;++i){ scanf("%u", &p[i]); }
        // sort(p, p+m);
        unsigned int &last = p[m-1];
        for(i=0;i<n;++i){
            Car& c = car[i];
            if (c.d > last) continue;
            if (c.a == 0) {
                if (c.v>V) set_nearby(c.d);
                continue;
            }
            if (c.a > 0) {
                if (c.v > V) {
                    set_nearby(c.d);
                    continue;
                }
                j = V2 - c.v*c.v;
                k = 2*c.a;
                idx = upper_bound(p, p+m, (unsigned int)(j/k) + c.d) - p;
                if (p[idx] > last) continue;
            } else {
                if (c.v<=V) continue;
                j = V2 - c.v*c.v;
                k = 2*c.a;
                idx = lower_bound(p, p+m, c.d) - p;
                int ft = ceil(j/k) + c.d;
                if (p[idx] >= ft) continue;
            }
            ++ans;
            flags[idx] = 1;
        }
        printf("%d %lu\n", ans, m - flags.count());
    } while(--T);
    fclose(stdin);
    fclose(stdout);
    return 0;
}