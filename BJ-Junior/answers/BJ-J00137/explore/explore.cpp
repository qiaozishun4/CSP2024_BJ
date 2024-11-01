#include <bits/stdc++.h>
using namespace std;
char a[2005][2005];
int mp[2005][2005];
int tot=0;
int main(){
    freopen("explor.in","r",stdin);
    freopen("explor.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int x,y,d;
        scanf("%d%d%d",&x,&y,&d);
        for(int j=1;j<=n;j++){
            for(int l=1;l<=m;l++){
                char c;
                scanf("%c",&c);
                a[j][l]=c;
            }
        }
        for(int j=1;j<=k;j++){
            if(d==0){
                y++;
            }if(d==1){
                x++;
            }if(d==2){
                y--;
            }if(d==3){
                x--;
            }
            if((x>n||x<1)||(y<1||y>m)){
                if(d==0){
                    y--;
                }if(d==1){
                    x--;
                }if(d==2){
                    y++;
                }if(d==3){
                    x++;
                }d%=d+1;
            }
            if(a[x][y]='x'){
                if(d==0){
                    y--;
                }if(d==1){
                    x--;
                }if(d==2){
                    y++;
                }if(d==3){
                    x++;
                }d%=d+1;
            }
            if(mp[x][y]==0){
                tot++;
            }
            mp[x][y]=1;
        }
        printf("%d\n",tot);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
