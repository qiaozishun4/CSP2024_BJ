#include<bits/stdc++.h>
using namespace std;
int n,m,k;
char a[1010][1010];
bool vis[1010][1010];
int x,y,d;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool check(int x,int y){
    return x>0 && y>0 && x<=n && y<=m && a[x][y]=='.';
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)vis[i][j]=0;
        vis[x][y]=true;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)cin>>a[i][j];
        while(k--){

            int nx=x+dx[d],ny=y+dy[d];
            //cout<<x<<' '<<y<<' '<<d<<' '<<nx<<' '<<ny<<'\n';
            if(check(nx,ny)){
                x=nx;y=ny;
            }else{
                d++;
                d%=4;
            }
            vis[x][y]=true;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j])ans++;
                //cout<<vis[i][j]<<' ';
            }
            //cout<<'\n';
        }


        cout<<ans<<'\n';
    }
    return 0;
}
