#include <bits/stdc++.h>
using namespace std;

int ax[100010];

int x[9];

int a[100010];

int c[100010];

int d[20][100010];

int part[20][100010];

int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> ax[i];
    }
    for(int i=1; i<=m; i++)
    {
        cin >> c[i];
    }
    int k = 0, mul = 1;
    while(mul < n)
    {
        mul *= 2;
        k ++;
    }
    for(int i=1; i<=k; i++)
    {
        int powerful = pow(2, k - i);
        for(int j=1; j<=powerful; j++)
        {
            cin >> d[i][j];
        }
    }
    int T;
    cin >> T;
    while(T--)
    {
        for(int i=0; i<=3; i++)
        {
            cin >> x[i];
        }
        for(int i=1; i<=n; i++)
        {
            a[i] = ax[i] % x[i % 4];
        }
        long long ans = 0;
        for(int Testm=1; Testm<=m; Testm++)
        {
            n = c[Testm];
            int k = 0, mul = 1;
            while(mul < n)
            {
                mul *= 2;
                k ++;
            }
            for(int i=1; i<=n; i++)
            {
                part[1][i] = i;
            }
            for(int i=1; i<=k; i++)
            {
                int powerful = pow(2, k - i);
                for(int j=1; j<=powerful; j++)
                {
                    if(d[i][j])
                    {
                        if(a[part[i][j * 2]] > i)
                        {
                            part[i + 1][j] = part[i][j * 2];
                        }
                        else part[i + 1][j] = part[i][j * 2 - 1];
                    }
                    else
                    {
                        if(a[part[i][j * 2 - 1]] > i)
                        {
                            part[i + 1][j] = part[i][j * 2 - 1];
                        }
                        else part[i + 1][j] = part[i][j * 2];
                    }
                }
            }
            int champ = part[k + 1][1];
            ans = ans ^ (1ll * Testm * champ);
        }
        cout << ans << endl;
    }
}
