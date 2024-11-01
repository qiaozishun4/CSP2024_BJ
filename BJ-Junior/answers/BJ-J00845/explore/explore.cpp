#include<bits/stdc++.h>
using namespace std;
int vis[1005][1005];
int a[1005][1005];
int dx1[4]={0,1,0,-1},dy1[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        for(int i=0;i<=1001;i++){
            for(int j=0;j<=1001;j++){
                vis[i][j]=0;
                a[i][j]=0;
            }
        }
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        char c;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
               cin>>c;
               if(c=='.'){
                   vis[i][j]=1;
               }else if(c=='x'){
                   vis[i][j]=-1;
               }
            }
        }
        a[x][y]=1;
        for(int i=1;i<=k;i++){
            int fx=x+dx1[d],fy=y+dy1[d];
            if(fx>=1&&fx<=n&&fy>=1&&fy<=m&&vis[fx][fy]==1){
                x=fx;
                y=fy;
                a[fx][fy]=1;
            }else{
                d=(d+1)%4;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]==1){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
