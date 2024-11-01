#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int T, n, A[200001], p[200001];
int c[1000001], lst[200001];
int dp[200001];

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%d", &T);
    while(T--) {
        memset(c, 0, sizeof(c));
        memset(lst, 0, sizeof(lst));
        memset(dp, 0, sizeof(dp));
        scanf("%d", &n);
        for(int i = 1;i <= n;i++) scanf("%d", &A[i]);
        for(int i = 1;i <= n;i++) p[i] = p[i - 1] + (A[i] == A[i - 1]) * A[i];
        int mx = 0;
        for(int i = 1, j;i <= n;i++) {
            if(c[A[i]]) lst[i] = c[A[i]];
            j = lst[i];
            while(j > 0) {
                if(A[i] == A[j + 1]) dp[i] = max(dp[i], dp[j] + A[i]);
                else dp[i] = max(dp[i], dp[j + 1] + A[i] + p[i - 1] - p[j + 1]);
                j = lst[j];
            }
            mx = max(mx, dp[i]);
            c[A[i]] = i;
        }
        printf("%d\n", mx);
    }
    return 0;
}

