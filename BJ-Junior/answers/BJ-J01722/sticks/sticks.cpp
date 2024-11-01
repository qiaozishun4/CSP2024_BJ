#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int N = 1e3 + 10, W = 5e4 + 10;
__int128 dp[N], INF;
int T, n;
inline void print(__int128 x)
{
    if(!x) return;
    print(x / 10);
    putchar(x % 10 + '0');
}
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        INF = 0;
        cin >> n;
        if(n != 1 && n % 7 == 1)
        {
            int k = n / 7 - 1;
            cout << 10;
            for(int i = 1;i <= k;++i)
                cout << 8;
            cout << "\n";
            continue;
        }
        if(n != 0 && n % 7 == 0)
        {
            int k = n / 7;
            for(int i = 1;i <= k;++i)
                cout << 8;
            cout << "\n";
            continue;
        }
        for(int i = 1;i <= n / 2;++i)
            INF = INF * 10 + 9;
        for(int i = 0;i <= n;++i)
            dp[i] = INF;
        for(int i = 1;i <= 10;++i)
            if(dp[a[i]] == INF)
                dp[a[i]] = i;
        for(int i = 0;i <= 10;++i)
            for(int j = a[i];j <= n;++j)
                if(dp[j - a[i]] * 10 + i < dp[j])
                    dp[j] = dp[j - a[i]] * 10 + i;
        if(dp[n] == INF)
            cout << "-1\n";
        else
        {
            print(dp[n]);
            putchar('\n');
        }
    }
    return 0;
}
