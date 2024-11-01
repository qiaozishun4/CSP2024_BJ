#include <iostream>

using namespace std;

char map[1007][1007];

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int t,n,m,k,x,y,face,ans,x1,y1;

    cin >> t;

    while(t --)
    {
        ans = 1;
        cin >> n >> m >> k >> x >> y >> face;

        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= m;j ++)
                cin >> map[i][j];

        while(k --)
        {
            map[x][y] = ' ';

            if(face == 0)x1 = x,y1 = y + 1;
            else if(face == 1)x1 = x + 1,y1 = y;
            else if(face == 2)x1 = x,y1 = y - 1;
            else if(face == 3)x1 = x - 1,y1 = y;

            if(x1 < 1 || x1 > n || y1 < 1 || y1 > m || map[x1][y1] == 'x')
                face = (face + 1) % 4;
            else
                x = x1,y = y1,ans += map[x1][y1] == ' ' ? 0 : 1;


        }

        cout << ans << endl;
    }

    return 0;
}
