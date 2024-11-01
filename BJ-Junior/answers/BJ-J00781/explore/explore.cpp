//correct!
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int fx[4]={0,1,0,-1},fy[4]={1,0,-1,0};
int x,y,f;
int n,m,k,t,tx,ty,ans;
char c[1005][1005];
bool vis[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>f;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                c[i][j]=getchar();
                while(c[i][j]!='x'&&c[i][j]!='.')c[i][j]=getchar();
            }
        }
        ans=1;
        vis[x][y]=1;
        for(int i=1;i<=k;i++){
            tx=x+fx[f];
            ty=y+fy[f];
            if(ty<1||ty>m||tx<1||tx>n||c[tx][ty]=='x')f=(f+1)&3;
            else x=tx,y=ty;
            if(!vis[x][y])ans++;
            vis[x][y]=1;
        }
        memset(vis,0,sizeof vis);
        cout<<ans<<'\n';
    }
    return 0;
}
