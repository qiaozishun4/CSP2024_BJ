#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 5;
const int MAXC = 105;
int T;
int n;
int a[MAXN];
ll **dp[MAXN];

inline int val(int x,int y){
    if (x == y)return y;
    return 0;
}

inline void update(ll &x,ll y){
    x = max(x,y);
}

inline void print(ll x){
    if (x < 0)printf("inf ");
    else printf("%-3lld ",x);
}

int main(){
    #ifndef kevin
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    #endif
    scanf("%d",&T);
    while (T --){
        scanf("%d",&n);
        int m = (n <= 100 ? n : 10);
        for (int i = 0;i <= n;i ++){
            if (i)scanf("%d",a + i);
            dp[i] = new ll*[m + 1];
            for (int j = 0;j <= m;j ++){
                dp[i][j] = new ll[m + 1];
                for (int k = 0;k <= m;k ++)dp[i][j][k] = 0xc0c0c0c0c0c0c0c0;
            }
        }
        dp[0][0][0] = 0;
        // printf("DP matrix:\n");
        // for (int j = 0;j <= m;j ++){
        //     for (int k = 0;k <= m;k ++)print(dp[0][j][k]);
        //     printf("\n");
        // }
        for (int i = 1;i <= n;i ++){
            for (int j = 0;j <= m;j ++){
                for (int k = 0;k <= m;k ++){
                    // i is red
                    update(dp[i][a[i]][k],dp[i - 1][j][k] + val(j,a[i]));
                    update(dp[i][j][a[i]],dp[i - 1][j][k] + val(k,a[i]));
                }
            }
            // printf("DP matrix:\n");
            // for (int j = 0;j <= m;j ++){
            //     for (int k = 0;k <= m;k ++)print(dp[i & 1][j][k]);
            //     printf("\n");
            // }
        }
        ll ans = 0;
        for (int i = 0;i <= m;i ++)
            for (int j = 0;j <= m;j ++)
                ans = max(ans,dp[n][i][j]);
        printf("%lld\n",ans);
        for (int i = 0;i <= n;i ++){
            for (int j = 0;j <= m;j ++)delete[] dp[i][j];
            delete[] dp[i];
        }
    }
    return 0;
}