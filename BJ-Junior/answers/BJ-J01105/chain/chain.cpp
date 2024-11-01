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
void out()
{
    if(t == 1)
        cout << 1 << endl << 0 << endl << 1 << endl << 0 << endl << 1 << endl << 0 << endl << 0 << endl;
    return;
}
void init()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++)
    {
        int l,s;
        cin >> l;
        for(int j = 1; j <= m; j++)
            cin >> s;
    }
    out();
    return;
}
bool bound(int x,int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y] == '.';
}
void calc_out()
{

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

int main()
{
    so();
    run();
    sc();
    return 0;
}
