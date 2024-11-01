#include <bits/stdc++.h>
using namespace std;
int cnt,k,m,n,qqq,xx,yy;
char map_[1005][1005];
void dfs(int x,int y,int d,int k)
{
    while(qqq < k)
    {
        if(d == 0)
        {
            if(map_[x][y+1] == 'x' || y+1 > m)
            {
                d = (d+1)%4;
                k--;
                if(k == qqq) break;
            }
            else
            {
                y = y+1;
                k--;
                if(map_[x][y] == '.')
                {
                    map_[x][y] = '@';
                    cnt++;
                    if(x == xx && y == yy) cnt--;
                }
            }
        }
        if(d == 1)
        {
            if(map_[x+1][y] == 'x' || x+1 > n)
            {
                d = (d+1)%4;
                k--;
                if(k == qqq) break;
            }
            else
            {
                x = x+1;
                k--;
                if(map_[x][y] == '.')
                {
                    map_[x][y] = '@';
                    cnt++;
                    if(x == xx && y == yy) cnt--;
                }
            }
        }
        if(d == 2)
        {
            if(map_[x][y-1] == 'x' || y-1 <= 0)
            {
                d = (d+1)%4;
                k--;
                if(k == qqq) break;
            }
            else
            {
                y = y-1;
                k--;
                if(map_[x][y] == '.')
                {
                    map_[x][y] = '@';
                    cnt++;
                    if(x == xx && y == yy) cnt--;
                }
            }
        }
        if(d == 3)
        {
            if(map_[x-1][y] == 'x' || x-1 <= 0)
            {
                d = (d+1)%4;
                k--;
                if(k == qqq) break;
            }
            else
            {
                x = x-1;
                k--;
                if(map_[x][y] == '.')
                {
                    map_[x][y] = '@';
                    cnt++;
                    if(x == xx && y == yy) cnt--;
                }
            }
        }
    }
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int fff = 1;fff <= T;fff++)
    {
        int k;
        cin>>n>>m>>k;
        int x0,y0,d0;
        cin>>x0>>y0>>d0;
        xx = x0,yy = y0;
        map_[x0][y0] = '@';
        cnt++;
        for(int i = 1;i <= n;i++)
        {
            string map1;
            cin>>map1;
            for(int j = 1;j <= m;j++)
            {
                map_[i][j] = map1[j-1];
            }
        }
        dfs(x0,y0,d0,k);
        cout<<cnt<<endl;
        cnt = 0;
    }
    fclose(stdin);
    fclose(stdout);
}
