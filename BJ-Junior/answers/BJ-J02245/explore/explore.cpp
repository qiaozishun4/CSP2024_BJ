#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int t,ans,n,m,k,d;
char a[1010][1010];
bool vis[1010][1010];
void dfs(int x,int y,bool f){
    if(vis[x][y] && !f) return ;
    vis[x][y] = 1;
    --k;
    bool flag = false;
    int xa = x , ya = y;
    if(d == 0){
        y += 1;
        if(a[x][y] == '.' && 1 <= x && x <= n && 1 <= y && y <= m){
            if(k == 0) return ;
            ++ans;
            dfs(x,y,0);
        }
        else flag = true;
    }
    else if(d == 1){
        x += 1;
        if(a[x][y] == '.' && 1 <= x && x <= n && 1 <= y && y <= m){
            if(k == 0) return ;
            ++ans;
            dfs(x,y,0);
        }
        else flag = true;
    }
    else if(d == 2){
        y -= 1;
        if(a[x][y] == '.' && 1 <= x && x <= n && 1 <= y && y <= m){
            if(k == 0) return ;
            ++ans;
            dfs(x,y,0);
        }
        else flag = true;
    }
    else if(d == 3){
        x -= 1;
        if(a[x][y] == '.' && 1 <= x && x <= n && 1 <= y && y <= m){
            if(k == 0) return ;
            ++ans;
            dfs(x,y,0);
        }
        else flag = true;
    }
    if(flag){
        d = (d + 1) % 4;
        dfs(xa,ya,1);
    }
    return ;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        memset(vis,false,sizeof(vis));
        scanf("%d%d%d",&n,&m,&k);
        ans = 1;
        int x,y;
        scanf("%d%d%d",&x,&y,&d);
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                cin>>a[i][j];
            }
        }
        if(k == 1){
            if(d == 0){
                y += 1;
                if(a[x][y] == '.' && 1 <= x && x <= n && 1 <= y && y <= m){
                    printf("2\n");
                }
                else printf("1\n");
            }
            else if(d == 1){
                x += 1;
                if(a[x][y] == '.' && 1 <= x && x <= n && 1 <= y && y <= m){
                    printf("2\n");
                }
                else printf("1\n");
            }
            else if(d == 2){
                y -= 1;
                if(a[x][y] == '.' && 1 <= x && x <= n && 1 <= y && y <= m){
                    printf("2\n");
                }
                else printf("1\n");
            }
            else if(d == 3){
                x -= 1;
                if(a[x][y] == '.' && 1 <= x && x <= n && 1 <= y && y <= m){
                    printf("2\n");
                }
                else printf("1\n");
            }
        }
        else{
            dfs(x,y,0);
            printf("%d\n",ans);
        }
    }
    return 0;
}
