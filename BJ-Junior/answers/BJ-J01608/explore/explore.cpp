#include<bits/stdc++.h>
using namespace std;
int T;
int derection_x[4] = {0,1,0,-1};
int derection_y[4] = {1,0,-1,0};
void solve()
{
    int ans = 0;
    int n,m,k;
    int robotx,roboty,robotd;
    bool ifmove = 1;
    cin >> n >> m >> k;
    cin >> robotx >> roboty >> robotd;

    int i,j;
    string forestmap[n + 1];
    for (i = 1; i <= n; i++) cin >> forestmap[i];

    roboty--;
    forestmap[robotx][roboty] = '1';

    while (k)
    {
        int nx = robotx + derection_x[robotd];
        int ny = roboty + derection_y[robotd];
        if(nx >= 1 && nx <= n && ny >= 0 && ny < m && forestmap[nx][ny] != 'x')
        {
            robotx = nx;
            roboty = ny;
        }
        else robotd = (robotd + 1) % 4;

        if(forestmap[robotx][roboty] != 'x') forestmap[robotx][roboty] = '1';
        k--;
    }

    if(forestmap[robotx][roboty] != 'x') forestmap[robotx][roboty] = '1';

    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if(forestmap[i][j] == '1') ans++;
        }
    }

    cout  << ans  << "\n";
    return ;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    int i;
    cin >> T;
    for (i = 1; i <= T; i++) solve();
    return 0;
}
