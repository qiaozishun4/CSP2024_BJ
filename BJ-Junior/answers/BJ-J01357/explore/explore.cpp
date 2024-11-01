#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1002;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};

int t;
int n,m,k;
int x,y,d;
char ch[MAXN][MAXN];
bool vis[MAXN][MAXN];

void Clear()
{
    n = m = k = x = y = d = 0;
    memset(ch,0,sizeof(ch));
    memset(vis,false,sizeof(vis));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    cin >> t;
    while(t--)
    {
        Clear();
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 1;i <= n;i++)
            cin >> ch[i] + 1;
        
        vis[x][y] = true;
        while(k--)
        {
            int curx = dx[d] + x,cury = dy[d] + y;
            if(1 <= curx && curx <= n && 1 <= cury && cury <= m && ch[curx][cury] == '.')
            {
                x = curx,y = cury;
                vis[x][y] = true;
            }
            else
                d = (d + 1) % 4;
        }

        int cnt = 0;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
                if(vis[i][j])
                    cnt++;
        cout << cnt << '\n';
    }

    return 0;
}