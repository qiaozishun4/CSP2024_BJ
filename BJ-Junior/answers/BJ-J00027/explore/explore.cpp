#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e3+10;

int t,n,m,k,ans=1;
int x,y,d;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char maze[N][N];
bool vis[N][N];

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    cin >> t;
    for(int turn=0;turn<t;turn++){
        cin >> n >> m >> k >> x >> y >> d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin >> maze[i][j];

        vis[x][y] = true;
        for(int i=0;i<k;i++){
            int nx = x+dx[d];
            int ny = y+dy[d];
            if(1<=nx && nx<=n && 1<=ny && ny<=m && maze[nx][ny]=='.'){
                x = nx;
                y = ny;
                if(vis[x][y]) continue;
                ans++;
                vis[x][y] = true;
            }
            else
                d = (d+1)%4;
        }
        cout << ans << endl;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                vis[i][j] = false;
        ans = 1;
    }
    return 0;
}
