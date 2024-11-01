#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int NMAX = 110000;
const int MMAX = 110000;
const int RMAX = 25;
const int DMAX = 4 * NMAX;

int T;
int N, M, K;
int Ap[NMAX];
int A[NMAX];
int C[MMAX];
short D[DMAX];
int d_st[RMAX];
int win[NMAX];
int ans[NMAX];

int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 1;i <= N;i += 1) {
        scanf("%d", &Ap[i]);
    }
    for(int i = 1;i <= M;i += 1) {
        scanf("%d", &C[i]);
    }
    K = 0;
    while((1<<K) < N) {
        K += 1;
    }
    int d_pos = 1;
    for(int i = 1;i <= K;i += 1) {
        d_st[i] = d_pos;
        for(int j = 1;j <= (1<<(K - i));j += 1) {
            char ch;
            scanf(" %c", &ch);
            D[d_pos] = ch - '0';
            d_pos += 1;
        }
    }
    scanf("%d", &T);
    for(int t = 1;t <= T;t += 1) {
        int X[4] = {};
        for(int i = 0;i < 4;i += 1) {
            scanf("%d", &X[i]);
        }
        for(int i = 1;i <= N;i += 1) {
            A[i] = Ap[i] ^ X[i % 4];
            // printf("A[%d]: %d\n", i, A[i]);
            win[i] = i;
        }
        ans[1] = win[1];
        for(int r = 1;r <= K;r += 1) {
            for(int i = 1;i <= ((1<<(K - r)));i += 1) {
                int d_idx = d_st[r] + i - 1;
                int boss_idx = (D[d_idx]?win[2 * i]:win[2 * i - 1]);
                int cand_idx = (D[d_idx]?win[2 * i - 1]:win[2 * i]);
                // printf("round %d: D[%d]: %d, A[%d]: %d, A[%d]: %d",
                //     r, d_idx, D[d_idx], win[2 * i - 1], A[win[2 * i - 1]], win[2 * i], A[win[2 * i]]);
                if(A[boss_idx] >= r) {
                    win[i] = boss_idx;
                } else {
                    win[i] = cand_idx;
                }
                // printf(", win: %d\n", win[i]);
            }
            ans[1<<r] = win[1];
        }
        long long res = 0;
        for(int i = 1;i <= M;i += 1) {
            res ^= (long long)i * ans[C[i]];
            // printf("C[%d]: %d, idx: %d\n", i, C[i], ans[C[i]]);
            // printf("res: %lld\n", res);
        }
        printf("%lld\n", res);
    }
    exit(0);
}