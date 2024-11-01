#include <bits/stdc++.h>

using namespace std;

char g[1005][1005];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main ()
{
    freopen("explore.in" , "r" , stdin);
    freopen("explore.out" , "w" , stdout);

    int t;
    cin >> t;
    while(t--)
    {
        memset(g , 0 , sizeof(g));
        int n , m , k;
        int x , y , f;
        cin >> n >> m  >>k;
        cin >> x >> y >> f;
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                cin >> g[i][j];
            }
        }

        int face = f;
        int ans = 1;
        for(int i = 1;i<=k;i++)
        {
            int xx = x + dx[face];
            int yy = y + dy[face];
            if(1<= xx && xx <= n && 1 <= yy && yy <= m && g[xx][yy] != 'x')
            {
                x = xx;
                y = yy;
                ans ++;
            }
            else
            {

                face = (face + 1) % 4;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
