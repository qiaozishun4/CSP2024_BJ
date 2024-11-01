#include<bits/stdc++.h>
using namespace std;
bool a[1005][1005];
bool b[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        int x0,y0,d0;
        cin >> x0 >> y0 >> d0;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
            {
                char x;
                cin >> x;
                if(x == '.')a[i][j] = 0;
                else a[i][j] = 1;
            }
        int ans = 1,x = x0,y = y0,d = d0;
        b[x0][y0] = 1;
        for(int i = 1;i <= k;i++)
        {
            if(d == 0)
            {
                if(y + 1 > m || a[x][y+1] == 1)d++;
                else y++;
                if(b[x][y] == 0)
                   ans++,b[x][y] = 1;
            }
            else if(d == 1)
            {
                if(x + 1 > n || a[x+1][y] == 1)d++;
                else x++;
                if(b[x][y] == 0)
                   ans++,b[x][y] = 1;
            }
            else if(d == 2)
            {
                if(y - 1 < 1 || a[x][y-1] == 1)d++;
                else y--;
                if(b[x][y] == 0)
                   ans++,b[x][y] = 1;
            }
            else if(d == 3)
            {
                if(x - 1 < 1 || a[x-1][y] == 1)d = 0;
                else x--;
                if(b[x][y] == 0)
                   ans++,b[x][y] = 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
