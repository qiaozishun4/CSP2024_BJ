#include<bits/stdc++.h>
using namespace std;
int n,m,t,k,xx,yy,dd,ans,vis[1145][1145],shul;
char c[1145][1145];
void dfs(int x,int y,int d,int l){
    if(vis[x][y]==0){
        ans++;
        vis[x][y]=1;
    }
    if(ans>=shul) return;
    if(l==k) return;
    int dx=x,dy=y;
    if(d==0) dy+=1;
    if(d==1) dx+=1;
    if(d==2) dy-=1;
    if(d==3) dx-=1;
    if(c[dx][dy]=='.'&&dx>0&&dx<=n&&dy>0&&dy<=m) {
       // cout<<endl<<endl;
        dfs(dx,dy,d,l+1);
    }
    else if(dx<=0||dx>n||dy<=0||dy>m||c[dx][dy]=='x'){
        int ni;
        if(d==0) ni=1;
        if(d==1) ni=2;
        if(d==2) ni=3;
        if(d==3) ni=0;
        //cout<<c[dx][dy]<<" "<<dx<<" "<<dy<<" "<<d<<" "<<ni<<" "<<endl;
        dfs(x,y,ni,l+1);
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>xx>>yy>>dd;
        memset(vis,0,sizeof(vis));
        shul=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c[i][j];
                if(c[i][j]=='.') shul++;
            }
        }
        vis[xx][yy]=1;
        ans=1;
        dfs(xx,yy,dd,0);
        cout<<ans<<endl;
    }
    return 0;
}
