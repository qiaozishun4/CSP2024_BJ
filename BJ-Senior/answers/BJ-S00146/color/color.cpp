#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

const int NMAX = 210000;
const int VMAX = 1100000;

int T;
int N;
int A[NMAX];
long long f[NMAX];
long long g[VMAX];
bool empty[VMAX];
long long sum[NMAX];

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%d", &T);
    for(int t = 1;t <= T;t += 1) {
        scanf("%d", &N);
        for(int i = 1;i <= N;i += 1) {
            scanf("%d", &A[i]);
            sum[i] = sum[i - 1] + (A[i - 1] == A[i]?A[i]:0);
            empty[A[i]] = true;
        }
        long long premax = 0;
        for(int i = 1;i <= N;i += 1) {
            f[i] = sum[i];
            if(i >= 2) {
                f[i] = max(f[i], premax + sum[i]);
            }
            if(i + 1 <= N && !empty[A[i + 1]]) {
                f[i] = max(f[i], g[A[i + 1]] + sum[i] + A[i + 1]);
            }
            if(i == 1 || premax < f[i] - sum[i + 1]) {
                premax = f[i] - sum[i + 1];
            }
            if(empty[A[i]] || g[A[i]] < f[i] - sum[i + 1]) {
                empty[A[i]] = false;
                g[A[i]] = f[i] - sum[i + 1];
            }
        }
        printf("%lld\n", f[N]);
    }
    exit(0);
}