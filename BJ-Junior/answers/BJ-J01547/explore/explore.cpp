#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int T;
int n , m , k;
int x , y , d;
int x1[4]={0 , 1 , 0 , -1};
int yy1[4]={1 , 0 , -1 , 0};
int cnt;
char c[N][N];
bool vis[N][N];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i  =1; i <= n; i++)
        {
            for(int j  =1; j <= m; j++)
            {
                cin >> c[i][j];
                vis[i][j]=0;
            }
        }
        vis[x][y]=1;
        cnt = 0;
        int step = 0;
        while(step < k)
        {
            int xx = x+x1[d];
            int yy = y+yy1[d];
            if(xx < 1 || xx > n || yy < 1 || yy > m || c[xx][yy] == 'x'){
                d=(d+1)%4;
            }
            else {
                x=xx;
                y=yy;
                vis[x][y]=1;
            }
            step++;
        }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(vis[i][j])
                    cnt++;
        cout << cnt << endl;
    }

    return 0;
}
