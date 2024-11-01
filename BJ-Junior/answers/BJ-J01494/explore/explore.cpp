#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int q=0; q<t; q++){
        int n, m, k, x, y, d, ans = 0;
        scanf("%d%d%d", &n, &m, &k);
        scanf("%d%d%d", &x, &y, &d);
        char pos[1010][1010];
        int visit[1010][1010];
        memset(visit, 0, sizeof(visit));
        for(int i=0; i<n; i++){
            scanf("%s", &pos[i]);
        }
        x-=1; y-=1;
        visit[x][y]=1;
        for(int i=0; i<k; i++){
            int xx, yy;
            if(d==0) {xx=x; yy=y+1;}
            else if(d==1) {xx=x+1; yy=y;}
            else if(d==2) {xx=x; yy=y-1;}
            else if(d==3) {xx=x-1; yy=y;}

            if(xx<0||yy<0||xx>=n||yy>=m||pos[xx][yy]=='x')
                d=(d+1)%4;
            else{
                visit[xx][yy]=1;
                x=xx;
                y=yy;
            }
            //printf("%d %d %d\n", x,y,d);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //printf("%d ", visit[i][j]);
                ans+=visit[i][j];
            }
            //printf("\n");
        }
        printf("%d\n", ans);
    }
    return 0;
}
