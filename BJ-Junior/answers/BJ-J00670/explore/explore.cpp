#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
char s[1001][1002];
bool b[1001][1001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
        scanf("\n");
        for(int j=1;j<=n;j++)
            for(int k=1;k<=m+1;k++)
                scanf("%c",&s[j][k]);
        int ans=1;
        for(int j=1;j<=k;j++){
            if(d==0){
                if(y+1<=m&&s[x][y+1]=='.'){
                    if(!b[x][y+1])
                        b[x][y+1]=1,ans++;
                    y++;
                }
                else{
                    d=(d+1)%4;
                    continue;
                }
            }
            if(d==1){
                if(x+1<=n&&s[x+1][y]=='.'){
                    if(!b[x+1][y])
                        b[x+1][y]=1,ans++;
                    x++;
                }
                else{
                    d=(d+1)%4;
                    continue;
                }
            }
            if(d==2){
                if(y-1>=1&&s[x][y-1]=='.'){
                    if(!b[x][y-1])
                        b[x][y-1]=1;ans++;
                    y--;
                }
                else{
                    d=(d+1)%4;
                    continue;
                }
            }
            if(d==3){
                if(x-1>=1&&s[x-1][y]=='.'){
                    if(!b[x-1][y])
                        b[x-1][y]=1,ans++;
                    x--;
                }
                else{
                    d=(d+1)%4;
                    continue;
                }
            }
        }
        printf("%d\n",ans);
    }
}
