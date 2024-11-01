#include <bits/stdc++.h>
using namespace std;

char m[1010][1010];

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int t, n, m1, k, x, y, d, ans = 0;
    cin >> t ;
    for(int aass = 0; aass < t; aass++){
            ans = 0;
        cin>> n >> m1 >> k >> x >> y >> d;
    for(int i = 0; i < 1009;i++)
    {
        for(int j = 0; j < 1009;j++)
        {
            m[i][j] = '0';
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m1; j++)
        {
            cin >> m[i][j];
        }
    }
    m[x][y]='1';

    int x1, y1;
    for(int i = 0; i < k; i++)
    {
        x1 = x;
        y1 = y;
        if(d == 0)
            y1 = y+1;
        else if(d == 1)
            x1 = x+1;
        else if(d == 2)
            y1 = y-1;
        else if(d == 3)
            x1 = x-1;
        if(m[x1][y1] == '.' || m[x1][y1] == '1' )
        {
            x = x1;
            y = y1;
            m[x][y] = '1';
        }
        else
        {
            d = (d+1)%4;
        }
    }
    for(int i = 0; i <= n+1; i++)
    {
        for(int j = 0; j <= m1+1; j++)
        {
            if(m[i][j] == '1')
                ans++;
        }
    }
    cout << ans<<endl;}


    fclose(stdin);
    fclose(stdout);
    return 0;
}
