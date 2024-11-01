#include<bits/stdc++.h>
using namespace std;

int t,n,m,k,x,y,d,ans;
bool qwq[1005][1005];
bool vis[1005][1005];
char a;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        ans = 1;
        memset(qwq,1,sizeof(qwq));
        memset(vis,0,sizeof(vis));
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        vis[x][y] = 1;
        if (n == 1){
            for (int i = 1;i <= n;i++){
                for (int j = 1;j <= m;j++){
                    cin >> a;
                    if (a == 'x') break;
                    else ans++;
                }
            }
            cout << ans << endl;
            continue;
        }
        for (int i = 1;i <= n;i++){
            for (int j = 1;j <= m;j++){
                cin >> a;
                if (a == 'x') qwq[i][j] = 0;
            }
        }
        for (int i = 1;i <= k;i++){
            int x1 = x+dx[d],y1 = y+dy[d];
            if (x1 <= n && x1 >= 1 && y1 <= m && y1 >= 1 && qwq[x1][y1] == 1){
                if (vis[x1][y1] == 0){
                    vis[x1][y1] = 1;
                    ans++;
                }
                x = x1;y = y1;
            }
            else d = (d+1)%4;
        }
        cout << ans << endl;
    }
    return 0;
}