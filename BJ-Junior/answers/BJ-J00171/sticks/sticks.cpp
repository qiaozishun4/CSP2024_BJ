#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int NMAX = 110000;
const int DMAX = 10;

int T;
int N;
int digit_stick[DMAX] = {
    6, 2, 5, 5, 4, 5, 6, 3, 7, 6
};
int f[DMAX][NMAX];
bool valid[DMAX][NMAX];

void init()
{
    f[DMAX - 1][0] = 0;
    valid[DMAX - 1][0] = true;
    for(int d = DMAX - 1;d >= 0;d -= 1) {
        for(int i = 0;i < NMAX;i += 1) {
            if(d + 1 < DMAX) {
                f[d][i] = f[d + 1][i];
                valid[d][i] = valid[d + 1][i];
            }
            int pre_i = i - digit_stick[d];
            if(pre_i >= 0 && valid[d][pre_i]) {
                if(!valid[d][i] || f[d][i] > f[d][pre_i] + 1) {
                    valid[d][i] = true;
                    f[d][i] = f[d][pre_i] + 1;
                }
            }
        }
    }
}

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    init();
    scanf("%d", &T);
    for(int t = 1;t <= T;t += 1) {
        scanf("%d", &N);
        bool ok = false;
        int min_first_d = -1, min_n_digit = NMAX;
        for(int i = 1;i < DMAX;i += 1) {
            if(N - digit_stick[i] >= 0 && valid[0][N - digit_stick[i]]
                && f[0][N - digit_stick[i]] + 1 < min_n_digit) {
                min_first_d = i;
                min_n_digit = f[0][N - digit_stick[i]] + 1;
                ok = true;
            }
        }
        if(!ok) {
            printf("-1\n");
        } else {
            printf("%d", min_first_d);
            int n_left = N - digit_stick[min_first_d];
            int cur_f = min_n_digit - 1;
            int d = 0;
            while(n_left) {
                int nxt_n_left = n_left - digit_stick[d];
                int nxt_f = cur_f - 1;
                if(nxt_n_left >= 0 && valid[d][nxt_n_left]
                    && f[d][nxt_n_left] == nxt_f) {
                    n_left = nxt_n_left;
                    cur_f = nxt_f;
                    printf("%d", d);
                } else {
                    d = d + 1;
                }
            }
            printf("\n");
        }
    }
    exit(0);
}