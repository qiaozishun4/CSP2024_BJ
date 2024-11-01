#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 20005;
int a[N];
int dp[N][N];
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1;i <= n;i++)
        {
            scanf("%d", &a[i]);
        }
        for(int i = 1;i <= n;i++)for(int j = 1;j < i;j++)dp[i][j] = 0;
        for(int i = 1;i <= n;i++)
        {

            for(int j = 0;j < i-1;j++)
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j]); // same color
            }
            for(int j = 0;j < i-1;j++)
            {
                if(a[i] == a[j]) dp[i][i-1] = max(dp[i-1][j]+a[i], dp[i][i-1]);
            }
        }
        int ans = 0;
        for(int i = 1;i < n;i++) ans = max(ans, dp[n][i]);
        printf("%d\n", ans);
    }
    return 0;
}
