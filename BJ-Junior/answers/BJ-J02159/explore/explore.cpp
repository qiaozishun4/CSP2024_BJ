#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
long long sum = 1;
char a[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    for(int q = 1;q <= t;q++)
    {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        a[x][y] = ',';
        sum = 1;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                cin >> a[i][j];
            }
        }
        for(int i = 1;i <= k;i++)
        {
            int xx = x,yy = y;
            if(d == 0) yy++;
            else if(d == 1) xx++;
            else if(d == 2) yy--;
            else xx--;
            if((1 <= xx && xx <= n)&&(1 <= yy&&yy <= m)&&(a[xx][yy] != 'x'))
            {
                x = xx;
                y = yy;
                if(a[x][y] == '.')
                {
                    sum++;
                    a[x][y] =',';
                }
            }
            else
            {
                d = (d + 1) % 4;
            }
        }
        cout << sum<< endl;
    }
    return 0;
}
