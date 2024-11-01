#include <bits/stdc++.h>
using namespace std;

char a[1000][1000];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        int n,m,k,x,y,d,ans = 0;
        cin >> n >> m >> k >> x >> y >> d;
        for(int j = 1;j <= n;j++)
        {
            for(int k = 1;k <= m;k++)
            {
                cin >> a[j][k];
            }
        }
        for(int j = 1;j <= k;j++)
        {
            if(d == 3)
            {
                if(a[x - 1][y] != '.')
                {
                    d = 0;
                }
                else
                {
                    a[x][y] = a[x - 1][y];
                    ans++;
                }
            }
            else if(d == 2)
            {
                if(a[x][y - 1] != '.')
                {
                    d++;
                }
                else
                {
                    a[x][y] = a[x][y - 1];
                    ans++;
                }
            }
            else if(d == 1)
            {
                if(a[x + 1][y] != '.')
                {
                    d++;
                }
                else
                {
                    a[x][y] = a[x + 1][y];
                    ans++;
                }
            }
            else if(d == 0)
            {
                if(a[x][y + 1] != '.')
                {
                    d++;
                }
                else
                {
                    a[x][y] = a[x][y + 1];
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
