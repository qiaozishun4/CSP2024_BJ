#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,b[100010];
    char a[1000000][1000000];
    cin>>t;
    for (int i = 1;i <= t;i++)
    {
        int n,m,k,x,y,d,x1,y1,cnt = 1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for (int j = 1;j <= n;j++)
        {
            for (int l = 1;l<= m;l++)
            {
                cin>>a[j][l];
            }
        }
        for (int z = 1;z <= k;z++)
        {
            if (d == 0)
            {
                a[x1][y1] = a[x][y + 1];
                x1 = x;
                y1 = y + 1;
            }
            if (d == 1)
            {
                a[x1][y1] = a[x + 1][y];
                x1 = x + 1;
                y1 = y;
            }
            if (d == 2)
            {
                a[x1][y1] = a[x][y - 1];
                x1 = x;
                y1 = y - 1;
            }
            if (d == 3)
            {
                a[x1][y1] = a[x - 1][y];
                x1 = x - 1;
                y1 = y;
            }
            if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && a[x1][y1] == '.')
            {
                a[x][y] = a[x1][y1];
                x = x1;
                y = y1;
                cnt++;
            }
            else
            {
                d = (d + 1) % 4;
            }
        }
        b[i] = cnt;
    }
    for (int i = 1;i <= t;i++)
    {
        cout<<b[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}