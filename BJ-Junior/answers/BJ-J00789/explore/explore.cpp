#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        int n,m,k;
        int x,y,d;
        int ans=1;
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
        char s[1100][1100];
        int g[1100][1100]={};
        g[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>s[i][j];
            }
        }
        for(int i=1;i<=k;i++){
            if(d==0&&x>=1&&x<=n&&y+1>=1&&y+1<=m&&s[x][y+1]=='.'){
                y++;
                if(g[x][y]==0){
                    g[x][y]=1;
                    ans++;
                }
            }
            else if(d==1&&x+1>=1&&x+1<=n&&y>=1&&y<=m&&s[x+1][y]=='.'){
                x++;
                if(g[x][y]==0){
                    g[x][y]=1;
                    ans++;
                }
            }
            else if(d==2&&x>=1&&x<=n&&y-1>=1&&y-1<=m&&s[x][y-1]=='.'){
                y--;
                if(g[x][y]==0){
                    g[x][y]=1;
                    ans++;
                }
            }
            else if(d==3&&x-1>=1&&x-1<=n&&y>=1&&y<=m&&s[x-1][y]=='.'){
                x--;
                if(g[x][y]==0){
                    g[x][y]=1;
                    ans++;
                }
            }else{
                d=(d+1)%4;
            }
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
