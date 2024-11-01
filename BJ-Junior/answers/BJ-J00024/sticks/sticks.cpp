#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1e3 + 5;
int num[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int d[] = {0, 1, 7, 4, 2, 8};
int dp[N][N], tmp[N];
bool vis[N];
int dpp[N];

int f(int x)
{
    int cnt = 0;
    while (x > 1)
    {
        x /= 10;
        cnt++;
    }
    return cnt - 1;
}

void Copy(int x[], int y[])
{
    //cout << x[0] << endl;
    int t = x[0];
    for (int i = 0; i <= t; i++)
        y[i] = x[i];
    //y[1] = x[1];
    //cout << x[0] << endl;
}

bool Cmp(int x[], int y[])
{
    if (x[0] != y[0]) return x[0] < y[0];
    for (int i = x[0]; i >= 1; i--)
        if (x[i] != y[i])
            return x[i] < y[i];
    return false;
}

bool Put(int x[])
{
    for (int i = x[0]; i >= 1; i--)
        printf("%d", x[i]);

}

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (n % 7 == 0 && n >= 100)
        {
            for (int i = 1; i <= n / 7; i++) printf("8");
            printf("\n");
        }
        else if (n <= 500)
        {
            memset(dp, 0x3f, sizeof(dp));
            memset(dp[0], 0, sizeof(dp[0]));
            memset(tmp, 0, sizeof(tmp));
            memset(vis, false, sizeof(vis));
            //Put(dp[0]);
            vis[0] = true;
            for (int i = 1; i <= n; i++)
            {
                for (int p = 0; p < 6; p++)
                {
                    int j = d[p];
                    if (i == n && j == 0) j = 6;
                    if (i < num[j]) continue;
                    if (!vis[i - num[j]]) continue;
                    //cout << i << " " << j << endl;
                    vis[i] = true;
                    Copy(dp[i - num[j]], tmp);
                    tmp[0]++;
                    tmp[tmp[0]] = j;
                    if (Cmp(tmp, dp[i])) Copy(tmp, dp[i]);
                }
            }
            if (vis[n])
            {
                Put(dp[n]);
                printf("\n");
            }
            else printf("-1\n");
        }
        else
        {
            int o = ceil(n / 7.0);
            int x = min(o, n - n / 7 * 7);
            int nn = n - (o - x) * 7;
            memset(dp, 0x3f, sizeof(dp));
            memset(dp[0], 0, sizeof(dp[0]));
            memset(tmp, 0, sizeof(tmp));
            memset(vis, false, sizeof(vis));
            //cout << o << " " << x << " " << nn << endl;
            //Put(dp[0]);
            vis[0] = true;
            for (int i = 1; i <= nn; i++)
            {
                for (int p = 0; p < 6; p++)
                {
                    int j = d[p];
                    if (i == nn && j == 0) j = 6;
                    if (i < num[j]) continue;
                    if (!vis[i - num[j]]) continue;
                    //cout << i << " " << j << endl;
                    vis[i] = true;
                    Copy(dp[i - num[j]], tmp);
                    tmp[0]++;
                    tmp[tmp[0]] = j;
                    if (Cmp(tmp, dp[i])) Copy(tmp, dp[i]);
                }
            }
            if (vis[nn]) Put(dp[nn]);
            else printf("-1\n");
            for (int i = 1; i <= o - x; i++)
                printf("8");
            printf("\n");
        }

    }
    return 0;
}
//ls cd ls g++ find.cpp
