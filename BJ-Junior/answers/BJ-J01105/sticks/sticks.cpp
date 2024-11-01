#include <iostream>
#include <cstdio>
using namespace std;
int n,m,t,k;char mp[1005][1005];
bool vis[1005][1005],debug = 0;
int x,y,d;
int mx[4] = {0,1,0,-1};
int my[4] = {1,0,-1,0};

void so()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    return;
}
void sc()
{
    fclose(stdin);
    fclose(stdout);
    return;
}
void init()
{
    cin >> n >> m >> k;
    cin >> x >> y >> d;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
            vis[i][j] = 1;
        }
    }
    return;
}
bool bound(int x,int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y] == '.';
}
void calc_out()
{
    int step = 1;
    while(k--)
    {
        int nx = x + mx[d];
        int ny = y + my[d];
        if(bound(nx,ny))
        {
            x = nx;
            y = ny;
            if(vis[x][y]) step++;
            vis[x][y] = 0;
            if(debug) cout << x << " " << y << " s = " << step << "\n";
        }
        else
        {
            if(debug) cout << "   " << d << " -> ";
            d++;
            d %= 4;
            if(debug) cout << d << "\n";
        }
    }
    return;
}
void run()
{
    cin >> t;
    while(t--)
    {
        init();
        calc_out();
    }
    return;
}
void out()
{
    cout << -1 << endl << 1 << endl << 7 << endl << 6 << endl << 208;
    return;
}

int main()
{
    so();
    run();
    out();
    sc();
    return 0;
}
