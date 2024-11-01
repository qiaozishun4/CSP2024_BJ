#include<bits/stdc++.h>
using namespace std;

constexpr char b[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bitset<(size_t)1e6> mpsrc, mpans;
unsigned short T, n, m, x, y, nx, ny, d, j, i;

static inline void setans(const unsigned short &x, const unsigned short &y) noexcept {
    mpans[x*1e3 + y] = 1;
}

static inline bool check(const unsigned short &x, const unsigned short &y) noexcept {
    return 0<=x && x<=n && 0<=y && y<=m && mpsrc[x*1e3 + y];
}

int main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    unsigned int k;
    char s;
    scanf("%hu", &T);
    do {
        mpsrc = mpans = 0;
        scanf("%hu %hu %u %hu %hu %hu", &n, &m, &k, &x, &y, &d);
        setans(--x, --y);
        getchar();
        for(i = 0;i<n;++i){
            for (j = 0;j<m;++j) {
                s = getchar();
                mpsrc[i*1e3 + j] = (s=='.');
            }
            getchar();
        }
        do {
            nx = x + b[d][0], ny = y + b[d][1];
            if (check(nx, ny)) {
                setans(x = nx, y = ny);
            } else {
                ++d;
                d &= 3;
            }
        } while(--k);
        printf("%lu\n", mpans.count());
    } while (--T);
    fclose(stdin);
    fclose(stdout);
    return 0;
}