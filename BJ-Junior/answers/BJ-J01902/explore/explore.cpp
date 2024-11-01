#include<iostream>
using namespace std;
bool a[1005][1005];
bool vis[1005][1005];
int main ()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int n,m,k;
        cin >> n >> m >> k;
        int x,y,d;
        cin >> x >> y >> d;
        vis[x][y]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char c;
                cin >> c;
                if(c=='x')
                {
                    a[i][j]=false;
                }
                if(c=='.')
                {
                    a[i][j]=true;
                }
            }
        }
        int nx,ny;
        for(int i=1;i<=k;i++)
        {
            if(d==0){
                nx=x;
                ny=y+1;
            }
            if(d==1){
                nx=x+1;
                ny=y;
            }
            if(d==2){
                nx=x;
                ny=y-1;
            }
            if(d==3){
                nx=x-1;
                ny=y;
            }

            if(nx>n||nx<1||ny>m||nx<1||a[nx][ny]==false){
                d=(d+1)%4;
            }
            else{
                vis[nx][ny]=true;
                x=nx;
                y=ny;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(vis[i][j]==true)
                    ans++;
                vis[i][j]=false;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
