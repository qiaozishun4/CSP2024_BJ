#include<iostream>
using namespace std;
int t, n, m, k, x, y, d, cnt;
char a[1001][1001];
int dx[4]={1, 0, -1, 0};
int dy[4]={0, -1, 0, 1};
bool visited[1001][1001];

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin >> a[i][j];
            }
        }
        for(int i=1; i<=k; i++)
        {
            int x1=x+dx[d];
            int y1=y+dy[d];
            char ch=a[x1][y1];
            if((x1<=0)||(x1>m)||(y1<=0)||(y1>n)||(ch=='x'))
            {
                d=(d+1)%4;
                continue;
            }
            else
            {
                x=x1;
                y=y1;
                if(!visited[x][y])
                {
                    cnt++;
                    visited[x][y]=1;
                }
            }
        }
        cout << cnt << endl;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                visited[x][y]=0;
            }
        }
    }
    return 0;
}