#include<bits/stdc++.h>
using namespace std;

const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int t,n,m,k,x,y,d,ans;
bool f[1010][1010];
char c[1010][1010];
void walk(){
    int tx=x+dx[d],ty=y+dy[d];
    if(tx<1||tx>n||ty<1||ty>m||c[tx][ty]=='x'){
        d=(d+1)%4;
        return;
    }
    x=tx,y=ty;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        memset(f,0,sizeof(f));
        ans=0;
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        for(int i=1;i<=n;i++){
            scanf("%s",c[i]+1);
        }
        f[x][y]=1;
        while(k--){
            walk();
            f[x][y]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(f[i][j])ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
