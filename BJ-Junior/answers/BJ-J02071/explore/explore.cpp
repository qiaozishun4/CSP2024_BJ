#include <bits/stdc++.h>
using namespace std;
int t;
int n,m,k,x,y,d;
char a[1005][1005];
int ans[1005];
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    for(int i=1; i<=t; i++)
    {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=m; k++)
            {
                cin >> a[j][k];
            }
        }
        a[x][y] = '0';
        while(k--)
        {
            if(d == 0)
            {
                if(x>=1 && x<=n && y+1>=1 && y+1<=m && a[x][y+1]!='x')
                {
                    y = y+1;
                    a[x][y] = '0';
                }
                else
                {
                    d = (d+1) % 4;
                }
            }
            else if(d == 1)
            {
                if(x+1>=1 && x+1<=n && y>=1 && y<=m && a[x+1][y]!='x')
                {
                    x = x+1;
                    a[x][y] = '0';
                }
                else
                {
                    d = (d+1) % 4;
                }
            }
            else if(d == 2)
            {
                if(x>=1 && x<=n && y-1>=1 && y-1<=m && a[x][y-1]!='x')
                {
                    y = y-1;
                    a[x][y] = '0';
                }
                else
                {
                    d = (d+1) % 4;
                }
            }
            else
            {
                if(x-1>=1 && x-1<=n && y>=1 && y<=m && a[x-1][y]!='x')
                {
                    x = x-1;
                    a[x][y] = '0';
                }
                else
                {
                    d = (d+1) % 4;
                }
            }
        }
        int num = 0;
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=m; k++)
            {
                if(a[j][k] == '0')
                {
                    num++;
                }
            }
        }
        ans[i] = num;
    }
    for(int i=1; i<=t; i++)
    {
        cout << ans[i] << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
