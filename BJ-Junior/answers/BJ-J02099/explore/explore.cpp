#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,k,x,y,d,sum = 0;
        char a[1005][1005];
        scanf("%d %d %d",&n,&m,&k);
        scanf("%d %d %d",&x,&y,&d);
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin >> a[i][j];
            }
        }
        for(int i = 0;i < k;i++)
        {
            if(d == 0)
            {
                if(1 <= x && x <= n && 1 <= y + 1 && y + 1 <= m && a[x][y + 1] != 'x' && a[x][y + 1] != '0')
                {
                    y++;
                    sum++;
                    a[x][y] = '0';
                }
                else
                    d = (d + 1) % 4;
                continue;
            }
            if(d == 1)
            {
                if(1 <= x + 1 && x + 1 <= n && 1 <= y && y <= m && a[x + 1][y] != 'x' && a[x + 1][y] != '0')
                {
                    x++;
                    sum++;
                    a[x][y] = '0';
                }
                else
                    d = (d + 1) % 4;
                continue;
            }
            if(d == 2)
            {
                if(1 <= x && x <= n && 1 <= y - 1 && y - 1 <= m && a[x][y - 1] != 'x' && a[x][y - 1] != '0')
                {
                    y--;
                    sum++;
                    a[x][y] = '0';
                }
                else
                    d = (d + 1) % 4;
                continue;
            }
            if(d == 3)
            {
                if(1 <= x - 1 && x - 1 <= n && 1 <= y && y <= m && a[x - 1][y] != 'x' && a[x - 1][y] != '0')
                {
                    x--;
                    sum++;
                    a[x][y] = '0';
                }
                else
                    d = (d + 1) % 4;
                continue;
            }
        }
        printf("%d\n",sum+1);
    }
    return 0;
}
