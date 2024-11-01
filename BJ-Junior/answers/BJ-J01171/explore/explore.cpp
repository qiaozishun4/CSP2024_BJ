#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m,k;
int x,y,d;
int fx[4]={0,1,0,-1};
int fy[4]={1,0,-1,0};
char a[1005][1005];
int vis[1005][1005];
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        vis[x][y]=1;
        while(k--){
            if(x+fx[d]>n||x+fx[d]<1||y+fy[d]>m||y+fy[d]<1||a[x+fx[d]][y+fy[d]]=='x'){
                d++;d%=4;
                continue;
            }
            x+=fx[d];y+=fy[d];
            vis[x][y]=1;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)ans+=vis[i][j];
        }
        cout<<ans<<'\n';
    }
    return 0;
}
