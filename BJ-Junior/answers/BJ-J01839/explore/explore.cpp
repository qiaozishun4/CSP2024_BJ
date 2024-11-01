#include<bits/stdc++.h>
using namespace std;
int n,m,q,x,y,d;
char a[1005][1005];
bool vis[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int ans = 1;
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        cin >> n >> m >> q >> x >> y >> d;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                cin >> a[i][j];
            }
        }
        for(int i = 1;i <= q;i++){
            vis[x][y] = 1;
            int newx = x,newy = y;
            if(d == 0)newy++;
            if(d == 1)newx++;
            if(d == 2)newy--;
            if(d == 3)newx--;
            if(a[newx][newy] == 'x' or newx > n or newx < 1 or newy > m or newy < 1)d = (d + 1) % 4;
            else x = newx,y = newy;
            if(vis[x][y] == 0) ans++;
            //cout << x << " " << y << " " << d << " " << i << " " << ans << endl;
            
        }
        cout << ans << endl;
    }
    return 0;
}