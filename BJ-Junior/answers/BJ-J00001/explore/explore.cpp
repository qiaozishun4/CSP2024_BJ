#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

char a[1005][1005];

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int sum=0;
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        int x, y, d;
        scanf("%d%d%d", &x, &y, &d);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin >> a[i][j];
            }
        }
        a[x][y] = '0';
        sum ++;
        for(int i=1; i<=k; i++)
        {
            if(d==0 && a[x][y+1]!='x' && y+1<=m) y+=1;
            else if(d==1 && a[x+1][y]!='x' && x+1<=n) x+=1;
            else if(d==2 && a[x][y-1]!='x' && y-1>=1) y-=1;
            else if(d==3 && a[x-1][y]!='x' && x-1>=1) x-=1;
            else d = (d+1)%4;

            if(a[x][y]=='.')
            {
                a[x][y] = '0';
                sum++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
