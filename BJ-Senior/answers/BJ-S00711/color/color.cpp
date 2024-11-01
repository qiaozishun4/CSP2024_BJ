#define up(i, l, r) for(auto i = l; i <= r; ++i)
#define dn(i, r, l) for(auto i = r; i >= l; --i)
#define FILE_NAME "color"

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

const int MAXN = 2e5 + 5;
int T, n, a[MAXN];
int dp[MAXN], answer;
bool col[MAXN];

void DFS(int i) {
    if(i > n) {
        int cur = 0;
        up(i, 1, n) {
            dn(j, i - 1, 1) {
                if(col[j] == col[i]) {
                    if(a[i] == a[j]) {
                        cur += a[i];
                    }
                    break;
                }
            }
        }
        answer = max(answer, cur);
        return;
    }
    col[i] = 0;
    DFS(i + 1);
    col[i] = 1;
    DFS(i + 1);
}

int main() {
    #ifdef FILE_NAME
    freopen(FILE_NAME".in" , "r", stdin );
    freopen(FILE_NAME".out", "w", stdout);
    #endif // FILE_NAME
    read(T);
    while(T--) {
        read(n);
        if(n <= 25) {
            up(i, 1, n) {
                read(a[i]);
            }
            answer = 0;
            //memset(col, 0, sizeof col);
            DFS(1);
            printf("%d\n", answer);
        }
        else {
            memset(dp, 0, sizeof(dp));
            up(i, 1, n) {
                dp[i + 1] = dp[i];
                if(a[i] == a[i - 1]) {
                    dp[i + 1] += a[i];
                }
            }
            up(i, 1, n) {
                up(j, 1, i - 1) {
                    if(a[i] == a[j]) {
                        dp[i] = max(dp[i], dp[i] + a[i] - (a[j] == a[j - 1]? a[j] : 0) + (a[j - 1] == a[j + 1]? a[j - 1] : 0));
                    }
                }
            }
            answer = *max_element(dp + 1, dp + 1 + n);
            printf("%d\n", answer);
        }
    }
    return 0;
}

