#include<bits/stdc++.h>
using namespace std;
char c[10005][10005];
bool vis[10005][10005];
int n,m,k;
int ans;
void dfs(int x,int y,int d,int stp,bool f){
    if(f&&!vis[x][y])ans++;
    vis[x][y]=1;
    //cout<<x<<' '<<y<<' '<<d<<' '<<stp<<' '<<f<<' '<<ans<<' '<<c[x][y]<<'\n';
    if(stp==k) {
        return ;
    }
    if((d==0&&c[x][y+1]=='x')||(d==1&&c[x+1][y]=='x')||(d==2&&c[x][y-1]=='x')||(d==3&&c[x-1][y]=='x')||(d==0&&y+1>m)||(d==1&&x+1>n)||(d==2&&y-1<1)||(d==3&&x-1<1)){
        dfs(x,y,(d+1)%4,stp+1,0);
    }
    else {
        if(d==0) dfs(x,y+1,d,stp+1,1);
        if(d==1) dfs(x+1,y,d,stp+1,1);
        if(d==2) dfs(x,y-1,d,stp+1,1);
        if(d==3) dfs(x-1,y,d,stp+1,1);
    }
}
int main(){
    freopen("explore5.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            cin>>c[i]+1;
        }
        ans=0;
        memset(vis,0,sizeof(vis));
        dfs(x,y,d,0,1);
        cout<<ans<<'\n';
 //       cout<<"######################\n";
    }
    return 0;
}
