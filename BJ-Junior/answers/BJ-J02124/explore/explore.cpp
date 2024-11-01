#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
int x,y,c;
char s[1024][1024];
int dis[1024][1024];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int moved(int u,int d){
    if(u == 0) return dis[x][y];
    int nx = x+dx[d],ny = y+dy[d];
    if(s[nx][ny] == 'x') return moved(u-1,(d+1)%4);
    if(dis[nx][ny] == 0) dis[nx][ny] = dis[x][y]+1;
    else dis[nx][ny] = dis[x][y];
    x = nx;
    y = ny;
    return moved(u-1,d);
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i = 0;i < 1024;i++){
            for(int j = 0;j < 1024;j++){
                s[i][j] = 'x';
            }
        }
        scanf("%d %d %d",&n,&m,&k);
        scanf("%d %d %d",&x,&y,&c);
        for(int i = 1;i <= n;i++){
            //getchar();
            for(int j = 1;j <= m;j++){
                cin >> s[i][j];
            }

        }
        dis[x][y] = 1;
        int ans = moved(k,c);
        printf("%d\n",ans);
        /*for(int i = 1;i <= n+1;i++){
            for(int j = 1;j <= m+1;j++){
                printf("%c",s[i][j]);
            }
            puts("");
        }
        for(int i = 1;i <= n+1;i++){
            for(int j = 1;j <= m+1;j++){
                printf("%d ",dis[i][j]);
            }
            puts("");
        }*/
        //printf("%c%d",s[1][6],dis[1][6]);
        //memset(dis,0,sizeof dis);
        for(int i = 0;i < 1024;i++){
            for(int j = 0;j < 1024;j++){
                dis[i][j] = 0;
            }
        }
    }
    return 0;
}
