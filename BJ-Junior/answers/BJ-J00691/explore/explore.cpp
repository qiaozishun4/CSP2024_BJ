#include<bits/stdc++.h>
using namespace std;
long int T,n,m,k,xin,yin,d,ans;
int x[]={0,1,0,-1};
int y[]={1,0,-1,0};
char mp[1005][1005];
int vis[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        ans=1;
        memset(mp,'x',sizeof(mp));
        memset(vis,0,sizeof(vis));
        scanf("%lld %lld %lld",&n,&m,&k);
        scanf("%lld %lld %lld",&xin,&yin,&d);
        vis[xin][yin]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }while(k--){
            int cnt=d%4;
            int xx=xin+x[cnt];
            int yy=yin+y[cnt];
            if(xx<1||xx>n||yy<1||yy>m||mp[xx][yy]=='x'){
                d++;
                continue;
            }xin=xx;
            yin=yy;
            vis[xx][yy]++;
            if(vis[xx][yy]>1) continue;
            ans++;
        }printf("%lld\n",ans);
    }
    return 0;
}
