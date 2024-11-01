#include <bits/stdc++.h>
using namespace std;

string a[1000];

struct bot
{
    int x;
    int y;
    int d;
}bot[1000000];

int run()
{
    int cnt = 0;
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int x0,y0,d0;
    scanf("%d%d%d",&x0,&y0,&d0);
    x0--;y0--;
    int d = d0;
    bot[0].x = x0;bot[0].y = y0;bot[0].d = d0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    a[x0][y0] = '*';
    for(int i = 0;i < k; i++)
    {
        if(bot[i].d == 0)
        {
            if(a[bot[i].x][(bot[i].y)+1] == '.' || a[bot[i].x][(bot[i].y)+1] == '*')
            {
                bot[i+1].y = (bot[i].y)+1;bot[i+1].x = bot[i].x;bot[i+1].d = bot[i].d;
                a[bot[i+1].x][bot[i+1].y] = '*';
            }
            else
            {
                bot[i+1].x = bot[i].x;bot[i+1].y = bot[i].y;
                bot[i+1].d = ((bot[i].d)+1)%4;
            }
        }
        else if(bot[i].d == 1)
        {
            if(a[(bot[i].x)+1][bot[i].y] == '.' || a[(bot[i].x)+1][bot[i].y] == '*')
            {
                bot[i+1].y = bot[i].y;bot[i+1].x = (bot[i].x)+1;bot[i+1].d = bot[i].d;
                a[bot[i+1].x][bot[i+1].y] = '*';
            }
            else
            {
                bot[i+1].x = bot[i].x;bot[i+1].y = bot[i].y;
                bot[i+1].d = ((bot[i].d)+1)%4;
            }
        }
        else if(bot[i].d == 2)
        {
            if(a[bot[i].x][(bot[i].y)-1] == '.' || a[bot[i].x][(bot[i].y)-1] == '*')
            {
                bot[i+1].y = (bot[i].y)-1;bot[i+1].x = bot[i].x;bot[i+1].d = bot[i].d;
                a[bot[i+1].x][bot[i+1].y] = '*';
            }
            else
            {
                bot[i+1].x = bot[i].x;bot[i+1].y = bot[i].y;
                bot[i+1].d = ((bot[i].d)+1)%4;
            }
        }
        else if(bot[i].d == 3)
        {
            if(a[(bot[i].x)-1][bot[i].y] == '.' || a[(bot[i].x)-1][bot[i].y] == '*')
            {
                bot[i+1].y = bot[i].y;bot[i+1].x = (bot[i].x)-1;bot[i+1].d = bot[i].d;
                a[bot[i+1].x][bot[i+1].y] = '*';
            }
            else
            {
                bot[i+1].x = bot[i].x;bot[i+1].y = bot[i].y;
                bot[i+1].d = ((bot[i].d)+1)%4;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == '*')
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        cout << run() << endl;

    fclose(stdin);
    fclose(stdout);
}
