#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,xf,yf,df,cnt,ans=1,vis[1010][1010];
char a[1010][1010];
int cx[]={0,1,0,-1};
int cy[]={1,0,-1,0};
void dfs(long long x,long long y,long long d,long long cnt){
    int xx=x+cx[d];
    int yy=y+cy[d];
    if(cnt==0){
        return;
    }
    if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]=='.'){
        if(vis[xx][yy]==false){
            ans++;
        }
        vis[xx][yy]=true;
        dfs(xx,yy,d,cnt-1);
    }
    else{
        dfs(x,y,(d+1)%4,cnt-1);
    }

}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        ans=1;
        cin>>n>>m>>k>>xf>>yf>>df;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        memset(vis,0,sizeof(vis));
        dfs(xf,yf,df,k);
        cout<<ans<<endl;
    }
    return 0;
}
