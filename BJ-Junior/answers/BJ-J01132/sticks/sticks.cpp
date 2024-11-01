#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int cnt[15] = {6,2,5,5,4,5,6,3,7,6};
long long T, n, ans = 0;
long long min_ = 21474836;
void dfs (long long num, long long sum, int i, long long x) {
    if (sum == n) {
        min_ = min(min_, num);
    }
    if (sum > n) {
        return;
    }
    if (num > min_) {
        return;
    }
    if (i == 9) {
        return;
    }
    if (x == 1) {
        i += 1;
    }
    dfs(num*x+i, sum+cnt[i], i, x*10);
    dfs(num*x, sum, i+1, x*10);
    return;
}
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        ans = 0;
        if (n < 2) {
            ans = -1;

        } else {
            min_ = 21474836;
            dfs (0, 0, 0, 1);
            ans = min_;
        }

        printf("%lld\n", ans);
    }

    return 0;
}
