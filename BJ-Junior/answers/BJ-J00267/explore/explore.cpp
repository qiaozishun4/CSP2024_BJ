#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,m,vis[1005][1005];
char a[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
    scanf("%lld",&T);
	while(T--){
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        ll k,x,y,d;
        scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&k,&x,&y,&d);
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
        vis[x][y]=1;
        while(k--){
            if(d==0){
                if(y+1>m||a[x][y+1]=='x')d=1;
                else{
                    y++;
                    vis[x][y]++;
                }
            }else if(d==1){
                if(x+1>n||a[x+1][y]=='x')d=2;
                else{
                    x++;
                    vis[x][y]++;
                }
            }else if(d==3){
                if(x-1<1||a[x-1][y]=='x')d=0;
                else{
                    x--;
                    vis[x][y]++;
                }
            }else{
                if(y-1<1||a[x][y-1]=='x')d=3;
                else{
                    y--;
                    vis[x][y]++;
                }
            }
        }
        ll ans=0;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(vis[i][j])ans++;
        printf("%lld\n",ans);
	}
    return 0;
}

