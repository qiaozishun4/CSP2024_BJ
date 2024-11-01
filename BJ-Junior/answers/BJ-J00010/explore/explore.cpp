#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,vis[1010][1010],dx[]={0,1,0,-1},dy[]={1,0,-1,0};
char c[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        vis[x][y]=1;
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c[i][j];
            }
        }
        for(int i=1;i<=k;i++){
            int xx=x+dx[d];
            int yy=y+dy[d];
            if(xx>=1 && xx<=n && yy>=1 && yy<=m && c[xx][yy]=='.'){
                x=xx;
                y=yy;
                vis[xx][yy]=1;
            }else{
                d=(d+1)%4;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cnt+=vis[i][j];
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
