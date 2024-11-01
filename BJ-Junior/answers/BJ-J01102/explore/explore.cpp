#include <bits/stdc++.h>
using namespace std;
char maps[1005][1005];
int cnt[1005][1005];
int main()
{
    freopen("explore.in" , "r" , stdin);
    freopen("explore.out" , "w" , stdout);
    int x,y,d,nx,ny,nd,t,n,m,k;
    cin >> t;
    for (int p=0; p<t; p++)
    {
        //input
        int ans=0;
        cin >> n >> m >> k >> x >> y >> d;
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
                cin >> maps[i][j];
        //explore
        for(int i=0; i<k; ++i)
        {
            cnt[x][y] = 1;
            //0-y+  1-x+  2-y-  3-x-
            if(d==0){nx=x; ny=y+1;}
            else if(d==1){nx=x+1; ny=y;}
            else if(d==2){nx=x; ny=y-1;}
            else if(d==3){nx=x-1; ny=y;}
            //move and turn
            if(maps[nx][ny] == 'x' || nx<1 || ny<1 || nx>n || ny>m)
            {
                d=(d+1)%4;
            }
            else
            {
                x=nx; y=ny;
            }
        }
        //count
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
                if(cnt[i][j] == 1)
                    ans++;
        cout << ans << endl;
    }
    return 0;
}
