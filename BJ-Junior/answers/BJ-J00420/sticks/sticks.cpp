#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int T, n, dp[100005], a[100005], cnt;
int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i = 2; i <= 100000; i ++)
        for(int j = 2; j <= 7; j ++)
            if(i >= j)
                dp[i] = min(dp[i], dp[i - j] + 1);

    cin >> T;
    while(T --)
    {
        cin >> n;
        if(n == 1)
        {
            cout << -1 << endl;
            continue;
        }
        int flag = 0;
        while(n > 0)
        {
            int minn = 2e9, id = 0;
            for(int i = !flag; i <= 9; i ++)
                if(n >= num[i] && minn > dp[n - num[i]] + 1)
                {
                    minn = dp[n - num[i]] + 1;
                    id = i;
                }
            a[++ cnt] = id;
            n -= num[id];
            flag = true;
        }

        for(int i = 1; i <= cnt; i ++)
            cout << a[i];

        cout << endl;

        cnt = 0;
    }

    return 0;
}
