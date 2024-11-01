#include <bits/stdc++.h>
using namespace std;

int t;
int a[1005][1005];
int qwq[10] = {114514,0,1,1,0,0,-1,-1,0};
int ans = 1;

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    for(int awa = 1;awa <= t;awa++)
    {
        ans = 1;
        memset(a,0,sizeof(a));
        int n,m,k;
        cin >> n >> m >> k;
        int x,y,d;
        cin >> x >> y >> d;
        string str;
        for(int i = 1;i <= n;i++)
        {
            cin >> str;
            for(int j = 0;j < str.length();j++)
            {
                if(str[j] == 'x')
                {
                    a[i][j + 1] = 1;
                }
                else
                {
                    a[i][j + 1] = 0;
                }
            }
        }
        a[x][y] = 2;
        int xn,yn;
        for(int i = 1;i <= k;i++)
        {
            xn = x + qwq[d * 2 + 1];
            yn = y + qwq[d * 2 + 2];
            bool qaq = false;
            if(a[xn][yn] != 1 && 1 <= xn && xn <= n && 1 <= yn && yn <= m)
            {
                qaq = true;
                if(a[x][y] == 0)
                {
                    a[x][y] = 2;
                    ans++;
                }
                x = xn;
                y = yn;
            }
            else
            {
                d = (d + 1) % 4;
            }
            if(qaq && i == k && a[x][y] != 2)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
