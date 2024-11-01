#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,cnt,vis[1010][1010];
char mp[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        memset(vis,0,sizeof(vis));
        vis[x][y]=1;
        cnt=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        for(int i=1;i<=k;i++){
            int xx=x,yy=y;
            if(d==0){
                yy++;
            }else if(d==1){
                xx++;
            }else if(d==2){
                yy--;
            }else{
                xx--;
            }
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&mp[xx][yy]=='.'){
                x=xx,y=yy;
                if(!vis[x][y]){
                    vis[x][y]=1;
                    cnt++;
                }
            }else{
                d=(d+1)%4;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
