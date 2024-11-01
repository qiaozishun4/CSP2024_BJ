#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,ans;
int x,y,d;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char dt[1005][1005];
int p[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>dt[i][j];
                p[i][j]=0;
            }
        }
        p[x][y]=1;
        while(k--){
            int tx=x+dx[d];
            int ty=y+dy[d];
            if(tx>0&&tx<=n&&ty>0&&ty<=m&&dt[tx][ty]=='.'){
                x=tx,y=ty;
                p[tx][ty]=1;
            }else{
                d=(d+1)%4;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[i][j]==1) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
