#include <iostream>
using namespace std;

int n,m,k,ni,mi,di;
char mp[1005][1005];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,-1,0,1};

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        cin >> ni >> mi >> di;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)cin >> mp[i][j];
        }
        int cnt = 1;
        for(int i = 1;i <= k;i++)
        {
            int nx = ni + dx[di];
            int ny = mi + dy[di];
            if(nx < 1 || nx > n || ny < 1 || ny > m || mp[nx][ny] == 'X')
            {
                di = (di+1) % 4;
            }
            else{
                ni = nx;
                mi = ny;
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
