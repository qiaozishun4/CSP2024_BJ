#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
bool f[N][N], fl[N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;
string s;
bool Cmp(int x, int y)
{
    if(x < 1 || y < 1 || x > n || y > m)
        return false;
    if(f[x][y] == true)
        return false;
    return true;
}
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        memset(f, 0, sizeof(f));
        memset(fl, 0, sizeof(fl));
        int k;
        cin >> n >> m >> k;
        int x, y, d;
        cin >> x >> y >> d;
        for(int i = 1;i <= n;i++)
        {
            cin >> s;
            for(int j = 0;j < s.size();j++)
            {
                if(s[j] == 'x')
                    f[i][j + 1] = true;
                else if(s[j] == '.')
                    f[i][j + 1] = false;
            }
        }
        int cnt = 1;
        fl[x][y] = true;
        for(int i = 1;i <= k;i++)
        {
            if(Cmp(x + dx[d], y + dy[d]) == true)
                x += dx[d], y += dy[d];
            else
                d = (d + 1) % 4;
            if(fl[x][y] == false)
                cnt++;
            fl[x][y] = true;
        }
        cout << cnt << endl;
    }
    return 0;
}