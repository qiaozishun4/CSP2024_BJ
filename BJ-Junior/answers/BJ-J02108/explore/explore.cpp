#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int d,flag,k,m,n,t,x0,x1,y0,y1;
    cin >> t;
    for (int i = 0;i < t;i++)
    {
        cin >> n >> m >> k;
        cin >> x0 >> y0 >> d;
        int ans = 1,x[k],y[k];
        string s[n];
        x[0] = x0;
        y[0] = y0;
        for (int j = 0;j < n;j++)
        {
            cin >> s[j];
        }
        for (int l = 0;l < k;l++)
        {
            if (d == 0)
            {
                x1 = x0;
                y1 = y0 + 1;
            }
            else if (d == 1)
            {
                x1 = x0 + 1;
                y1 = y0;
            }
            else if (d == 2)
            {
                x1 = x0;
                y1 = y0 - 1;
            }
            else
            {
                x1 = x0 - 1;
                y1 = y0;
            }
            if (1 <= x1 && x1 <= n && 1 <= y1 && y1 <= m && s[x1 - 1][y1 - 1] == '.')
            {
                x0 = x1;
                y0 = y1;
                flag = 1;
                for (int p = 0;p < ans;p++)
                {
                    if (x[p] == x0 && y[p] == y0)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    x[ans] = x0;
                    y[ans] = y0;
                    ans++;
                }
            }
            else
            {
                d = (d + 1) % 4;
            }
        }
        cout << ans << endl;
    }
    return 0;
}