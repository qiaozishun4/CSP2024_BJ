#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int t;
int n,m,k;
int x,y,d;
int ans;
char a[N][N];
bool vis[N][N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                cin >> a[i][j];
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                vis[i][j] = false;
            }
        }
        ans = 1;
        vis[x][y] = 1;
        while(k--){
            int nx,ny;
            if(d == 0){nx = x,ny = y + 1;}
            else if(d == 1){nx = x + 1,ny = y;}
            else if(d == 2){nx = x,ny = y - 1;}
            else{nx = x - 1,ny = y;}
            if(nx > n || ny > m || nx < 1 || ny < 1){d = (d + 1) % 4;continue;}
            if(a[nx][ny] == '.'){
                if(!vis[nx][ny]){ans++;vis[x][y] = true;}
                x = nx;y = ny;
                continue;
            }else{
                d = (d + 1) % 4;
                continue;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}