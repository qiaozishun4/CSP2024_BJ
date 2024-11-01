#include<bits/stdc++.h>
using namespace std;
int T,x,y,d,k,n,m,cnt,yy[4]={1,0,-1,0},xx[4]={0,1,0,-1};
char mp[1003][1003];
bool vis[1002][1002];
char ch;//[1002];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    //2
    cin>>T;
    while(T--){
        cin>>n>>m>>k>>x>>y>>d;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            //cin>>ch;
            for(int j=1;j<=m;j++){
                    cin>>mp[i][j];//=1;
            }
        }
        vis[x][y]=1;
        for(int i=1;i<=k;i++){
            int nx=x+xx[d],ny=y+yy[d];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='.'){
                x=nx,y=nx;
                //cout<<nx<<' '<<ny;
                vis[nx][ny]=1;
            }
            else d=(d+1)%4;
        }
        cnt=0;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(vis[i][j]) cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}
