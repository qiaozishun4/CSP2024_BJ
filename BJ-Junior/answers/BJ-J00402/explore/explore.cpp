#include<bits/stdc++.h>
using namespace std;
char g[1010][1010];
bool go[1010][1010];
int t,n,m,k,x,y,d;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    memset(go,0,sizeof go);
    cin >> t;
    while(t--)
    {
        memset(go,0,sizeof go);
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i = 1;i <= n;i++)
        {
            string s;
            cin >> s;
            for(int j = 0;j < s.size();j++)
            {
                g[i][j + 1] = s[j];
            }
        }
        while(k--)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny] == 'x')
            {
                d = (d + 1) % 4;
            }
            else
            {
                x = nx;
                y = ny;
                go[x][y] = true;
            }
            //cout << x << " " << y << " " << d << " " << cnt << " " << g[nx][ny] << endl;
        }
        int cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                if(go[i][j]) cnt++;
            }
        }
        cout << cnt + 1 << endl;
    }
    return 0;
}
