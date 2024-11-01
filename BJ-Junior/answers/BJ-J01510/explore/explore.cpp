#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 50;
int t,n,m,k;
int x,y,d;
char c[maxn][maxn];
bool vis[maxn][maxn];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        int ans = 0;
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                cin >> c[i][j];
                vis[i][j] = 0;
            }
        }
        vis[x][y] = 1;
        for(int i = 1;i <= k;i++){
            if(d == 0){
                if(c[x][y + 1] == '.' && y + 1 <= m && x <= n){
                    vis[x][y + 1] = 1;
                    y++;
                }
                else d = (d + 1) % 4;
            }
            else if(d == 1){
                if(c[x + 1][y] == '.' && x + 1 <= n && y <= m){
                    vis[x + 1][y] = 1;
                    x++;
                }
                else d = (d + 1) % 4;
            }
            else if(d == 2){
                if(c[x][y - 1] == '.' && x <= n && y - 1 >= 1){
                    vis[x][y - 1] = 1;
                    y--;
                }
                else d = (d + 1) % 4;
            }
            else if(d == 3){
                if(c[x - 1][y] == '.' && x - 1 >= 1 && y <= m){
                    vis[x - 1][y] = 1;
                    x--;
                }
                else d = (d + 1) % 4;
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(vis[i][j])ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
