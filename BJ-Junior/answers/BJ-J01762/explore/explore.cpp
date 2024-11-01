#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e4 + 10,M = 5 + 10;
char a[N][N];
int sum[M];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n,m,k,t;
    int x,y,d;
    cin >> t;
    for(int z = 1;z <= t;z++)
    {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin >> a[i][j];
            }
        }
        int a1 = x;
        int b1 = y;
        while(k--)
        {
            if(d == 0)
            {
                if(y + 1 <= m && a[x][y + 1] == '.')
                    y++,sum[z]++;
                else if(x == a1 && b1 == y)
                    d = (d + 1) % 4,sum[z]++,a1++;
                else
                    d = (d + 1) % 4;
            }
            else if(d == 1)
            {
                if(x + 1 <= n && a[x + 1][y] == '.')
                    x++,sum[z]++;
                else if(x == a1 && b1 == y)
                    d = (d + 1) % 4,sum[z]++,a1++;
                else
                    d = (d + 1) % 4;
            }
            else if(d == 2)
            {
                if(y - 1 > 0 && a[x][y - 1] =='.')
                    y--,sum[z]++;
                else if(x == a1 && b1 == y)
                    d = (d + 1) % 4,sum[z]++,a1++;
                else
                    d = (d + 1) % 4;
            }
            else if(d == 3)
            {
                if(x - 1 > 0 && a[x - 1][y] == '.')
                    x--,sum[z]++;
                else if(x == a1 && b1 == y)
                    d = (d + 1) % 4,sum[z]++,a1++;
                else
                    d = (d + 1) % 4;
            }
        }
    }
    for(int i = 1;i <= t;i++)
        cout << sum[i] << endl;
    return 0;
}
