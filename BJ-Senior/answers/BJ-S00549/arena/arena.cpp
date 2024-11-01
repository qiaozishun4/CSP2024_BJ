#include <bits/stdc++.h>
using namespace std;
int t, n, m, a[100020], c[100020], K = 1, x[10];
char d[100020][100020];
int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> c[i];
    int tmp = 2;
    while(tmp < n) tmp *= 2, K++;
    for(int i = 1; i <= K; i++)
    {
        for(int j = 1; j <= pow(2, K - i); j++) cin >> d[i][j];
    }
    cin >> t;
    while(t--)
    {
        int ans;
        for(int i = 0; i < 4; i++) cin >> x[i];
        for(int i = 1; i <= n; i++)
        {
            a[i] = a[i] ^ x[i % 4];
        }
        for(int k = 1; k <= m; k++)
        {
            int tmp = 2, cnt = 1;
            while(tmp < n) tmp *= 2, cnt++;
            /*
            for(int i = 1; i <= cnt; i++)
            {
                for(int j = 1; j <= c[k] / (i + 1); j++)
                {
                    if(d[i][j] == '1')
                    {

                    }
                }
            }
            */
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}