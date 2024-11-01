#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,ans;
char mp[1050][1050];
bool vis[1050][1050];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(vis,0,sizeof vis);
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        ans=1;
        vis[x][y]=1;
        while(k--){
            int xx=x+dx[d],yy=y+dy[d];
            if(xx>=1 && xx<=n && yy>=1 && yy<=m && mp[xx][yy]=='.'){
                if(!vis[xx][yy])ans++;
                vis[xx][yy]=1;
                x=xx,y=yy;
            }else{
                d=(d+1)%4;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}