#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char ch[1010][1010];
bool vis[1010][1010];
ll n,m;
bool is_ok(int x,int y,int d)
{
    if(d == 0)
    {
        if(x >= 1 && x <= n && y + 1 >= 1 && y + 1 <= m && ch[x][y + 1] == '.') return 1;
        return 0;
    }
    if(d == 1)
    {
        if(x + 1 >= 1 && x + 1 <= n && y >= 1 && y <= m && ch[x + 1][y] == '.') return 1;
        return 0;
    }
    if(d == 2)
    {
        if(x >= 1 && x <= n && y - 1 >= 1 && y - 1 <= m && ch[x][y - 1] == '.') return 1;
        return 0;
    }
    if(d == 3)
    {
        if(x - 1 >= 1 && x - 1 <= n && y >= 1 && y <= m && ch[x - 1][y] == '.') return 1;
        return 0;
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ll T;
    cin >> T;
    while(T--)
    {
        ll k,cnt = 1,cur = 0;
        cin >> n >> m >> k;
        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= m; j++)
            {
                vis[i][j] = 0;
            }
        }
        ll x,y,d;
        cin >> x >> y >> d;
        vis[x][y] = 1;
        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= m; j++)
            {
                cin >> ch[i][j];
            }
        }
        while(cnt < k)
        {
            while(!is_ok(x,y,d))
            {
                d = (d + 1) % 4;
                cur++;
                if(cur == k) break;
            }
            if(cur == k) break;
            if(d == 0) y += 1;
            else if(d == 1) x += 1;
            else if(d == 2) y -= 1;
            else x -= 1;
            if(!vis[x][y])
            {
                vis[x][y] = 1;
                cnt++;
            }
            cur++;
            if(cur == k) break;
        }
        cout << cnt << endl;
    }
    return 0;
}