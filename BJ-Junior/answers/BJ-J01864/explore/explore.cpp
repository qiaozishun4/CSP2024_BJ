#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
int T;
int vis[1005][1005];
int t[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    rep(i,T){
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;

        rep(j,n) rep(k,m){
            vis[j][k]=0;
            char xx;cin>>xx;
            if(xx=='.')t[j][k]=1;
            else t[j][k]=2;
        }

        vis[x][y]=1;
        int ans=1;
        while(k--){
            if(d==0){
                if(t[x][y+1]==1&&y+1<=m){
                    if(!vis[x][y+1])ans++;
                    vis[x][y+1]=1;
                    y++;
                }else{
                    d++;
                }
            }else if(d==1){
                if(t[x+1][y]==1&&x+1<=n){
                    if(!vis[x+1][y])ans++;
                    vis[x+1][y]=1;
                    x++;
                }else{
                    d++;
                }
            }else if(d==2){
                if(t[x][y-1]==1&&y-1>=1){
                    if(!vis[x][y-1])ans++;
                    vis[x][y-1]=1;
                    y--;
                }else{
                    d++;
                }
            }else if(d==3){
                if(t[x-1][y]==1&&x-1>=1){
                    if(!vis[x-1][y])ans++;
                    vis[x-1][y]=1;
                    x--;
                }else{
                    d=0;
                }
            }
        }
        cout << ans<<endl;
    }
    return 0;
}
