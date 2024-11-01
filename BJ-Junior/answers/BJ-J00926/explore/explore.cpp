#include <bits/stdc++.h>
using namespace std;
int t;
int m,n,k;
int x,y,d;
string a[1010];
bool vis[1010][1010];
int ans;
bool judge(int x_,int y_,int d_)
{
    if(d_ == 0)
        y_++;
    if(d_ == 1)
        x_++;
    if(d_ == 2)
        y_--;
    if(d_ == 3)
        x_--;
    if(1 <= x_ and x_ <= n and 0 <= y_ and y_ <= m - 1 and a[x_][y_] == '.')
        return true;
    return false;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        ans = 0;
        for(int o = 1;o <= n;o++)
            for(int q = 0;q <= m - 1;q++)
                vis[o][q] = 0;
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        y--;
        vis[x][y] = 1;
        for(int j = 1;j <= n;j++)
            cin >> a[j];
        for(int p = 1;p <= k;p++)
        {
            if(judge(x,y,d) == true)
            {
                if(d == 0)
                    y++;
                if(d == 1)
                    x++;
                if(d == 2)
                    y--;
                if(d == 3)
                    x--;
                vis[x][y] = 1;
            }
            else
                d = (d + 1) % 4;
        }
        for(int s = 1;s <= n;s++)
            for(int w = 0;w <= m - 1;w++)
                if(vis[s][w] == 1)
                    ans++;
        cout << ans << endl;
    }
    return 0;
}
