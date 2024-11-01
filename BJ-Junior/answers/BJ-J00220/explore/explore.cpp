#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
int x,y,d;
char g[1005][1005];
bool vis[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        int ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>g[i][j];
                vis[i][j]=false;
            }
        }
        vis[x][y]=true;
        while(k--){
            int x1=x,y1=y;
            if(d==0){
                y1=y+1;
            }if(d==1){
                x1=x+1;
            }if(d==2){
                y1=y-1;
            }if(d==3){
                x1=x-1;
            }
            if(x1>=1&&x1<=n&&y1>=1&&y1<=m&&g[x1][y1]=='.'){
                x=x1,y=y1;
                vis[x][y]=true;
            }else{
                d=(d+1)%4;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==true){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
