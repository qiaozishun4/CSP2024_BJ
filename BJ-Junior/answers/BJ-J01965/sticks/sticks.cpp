#include <cstdio>
using namespace std;
typedef long long ll;

#define MY_TEST

void read(int &rtn) {
    char c = getchar();
    bool rev = false;
    rtn = 0;
    while (c < '0' || c > '9')
        rev |= (c == '-'), c = getchar();
    while (c >= '0' && c <= '9')
        rtn = (rtn << 3) + (rtn << 1) + c - 48, c = getchar();
    if (rev) rtn = -rtn;
}
void read(ll &rtn) {
    char c = getchar();
    bool rev = false;
    rtn = 0LL;
    while (c < '0' || c > '9')
        rev |= (c == '-'), c = getchar();
    while (c >= '0' && c <= '9')
        rtn = (rtn << 3) + (rtn << 1) + c - 48, c = getchar();
    if (rev) rtn = -rtn;
}

const int maxn = 100010;
const int comp[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

int sticks[maxn];

bool doable(int digit, int nstick) {
    const int mn = (nstick + 7 - 1) / 7;
    const int mx = nstick >> 1;
    return mn <= digit && digit <= mx;
}

int main() {
    #ifdef MY_TEST
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    #else
    // freopen("sticks.in", "r", stdin);
    // freopen("sticks.out", "w", stdout);
    #endif

    int T, n; read(T);
    while (T--) {
        read(n);
        if (n < 2) {
            puts("-1");
            continue;
        }
        const int digit = (n + 7 - 1) / 7;
        for (int i = 0; i < digit; ++i) {
            for (int j = (i ? 0 : 1); j < 10; ++j) {
                if (doable(digit - i - 1, n - comp[j])){
                    sticks[i] = j;
                    n -= comp[j];
                    break;
                }
            }
        }
        for (int i = 0; i < digit; ++i)
            printf("%d", sticks[i]);
        puts("");
    }

    return 0;
}