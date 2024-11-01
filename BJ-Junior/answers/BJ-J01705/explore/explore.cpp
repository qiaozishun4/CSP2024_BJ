#include <bits/stdc++.h>
using namespace std;
char a[1010][1010];
bool flag[1010][1010];
int main()
{
    freopen("explore.in" , "r" , stdin);
    freopen("explore.out" , "w" , stdout);
    int t , n , m , k;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        int x , y , d;
        cin >> x >> y >> d;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        long long cnt = 1;
        for(int i = 1; i <= k; i++)
        {
            if(d == 0)
            {
                if(a[x][y + 1] != 'x' && y + 1 <= m)
                {
                    y += 1;
                    if(!flag[x][y])
                    {
                        cnt++;
                        flag[x][y] = 1;
                    }
                }
                else
                {
                    d += 1;
                    d %= 4;
                }
            }
            else if(d == 1)
            {
                if(a[x + 1][y] != 'x' && x + 1 <= n)
                {
                    x += 1;
                    if(!flag[x][y])
                    {
                        cnt++;
                        flag[x][y] = 1;
                    }
                }
                else
                {
                    d += 1;
                    d %= 4;
                }
            }
            else if(d == 2)
            {
                if(a[x][y - 1] != 'x' && y - 1 >= 1)
                {
                    y -= 1;
                    if(!flag[x][y])
                    {
                        cnt++;
                        flag[x][y] = 1;
                    }
                }
                else
                {
                    d += 1;
                    d %= 4;
                }
            }
            else if(d == 3)
            {
                if(a[x - 1][y] != 'x' && x - 1 >= 1)
                {
                    x -= 1;
                    if(!flag[x][y])
                    {
                        cnt++;
                        flag[x][y] = 1;
                    }
                }
                else
                {
                    d += 1;
                    d %= 4;
                }
            }
        }
        cout << cnt << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
