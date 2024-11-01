include<bits/stdc++.h>
using namespace std;
const int N=1e3+1;
int t,n,m,k,x,y,d,i,j,fx[]={0,1,0,-1},fy[]={1,0,-1,0},ans,xx,yy;
char di[N][N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>t;
    while(t--){
        bool vis[N][N]={};
        cin>>n>>m>>k>>x>>y>>d;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                cin>>di[i][j];
        ans=1,vis[x][y]=1;
        while(k--){
            xx=x+fx[d],yy=y+fy[d];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&di[xx][yy]=='.'){
                x=xx,y=yy;
                if(!vis[x][y]){
                    ans++;
                    vis[x][y]=1;
                }
            }
            else
                d=(d+1)%4;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
