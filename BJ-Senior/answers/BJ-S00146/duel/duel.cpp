#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int NMAX = 110000;

int N;
int R[NMAX];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 1;i <= N;i += 1) {
        scanf("%d", &R[i]);
    }
    sort(R + 1, R + N + 1);
    int n_left = 0;
    int pos = 1;
    while(pos <= N) {
        int n_cur_r = 0;
        int r_cur = R[pos];
        while(pos <= N && R[pos] == r_cur) {
            pos += 1;
            n_cur_r += 1;
        }
        n_left = max(0, n_left - n_cur_r) + n_cur_r;
        // printf("r: %d, n: %d, n_left: %d\n", r_cur, n_cur_r, n_left);
    }
    printf("%d\n", n_left);
    exit(0);
}