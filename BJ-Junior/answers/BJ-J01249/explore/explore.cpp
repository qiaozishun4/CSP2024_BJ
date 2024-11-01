#include<bits/stdc++.h>
using namespace std;
string a[1010];
bool cnt[1010][1010];

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, k, x, y, d, ans = 0;
        cin >> n >> m >> k >> x >> y >> d;
        x--;
        y--;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            for(int j=0;j<m;j++) cnt[i][j] = 0;
        }
        cnt[x][y] = 1;
        while(k--)
        {
            int nx = x, ny = y;
            if(d == 0) ny++;
            else if(d == 1) nx++;
            else if(d == 2) ny--;
            else if(d == 3) nx--;
            if(0<=nx && nx<n && 0<=ny && ny<m && a[nx][ny]=='.')
            {
                x = nx;
                y = ny;
            }
            else d = (d + 1) % 4;
            cnt[x][y] = 1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(cnt[i][j]) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
