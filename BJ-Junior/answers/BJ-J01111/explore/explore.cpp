#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, x, y, d;
char a[1005][1005];
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        int sum = 1;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= k; i++)
        {
            if(d==0)
            {
                if(a[x][y+1] == '.')
                {
                    sum++;
                    y+=1;
                }
                else
                {
                    d = (d+1)%4;
                }
            }
            else if(d==1)
            {
                if(a[x+1][y] == '.')
                {
                    sum++;
                    x+=1;
                }
                else
                {
                    d = (d+1)%4;
                }
            }
            else if(d==2)
            {
                if(a[x][y-1] == '.')
                {
                    sum++;
                    y-=1;
                }
                else
                {
                    d = (d+1)%4;
                }
            }
            else if(d==3)
            {
                if(a[x-1][y] == '.')
                {
                    sum++;
                    x-=1;
                }
                else
                {
                    d = (d+1)%4;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
