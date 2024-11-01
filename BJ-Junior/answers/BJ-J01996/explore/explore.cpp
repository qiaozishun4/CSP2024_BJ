#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,nx,ny,ans=0;
char maps[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>x>>y>>d;
        ans=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)cin>>maps[i][j];
        for(int i=0;i<k;i++){
            nx=x+dx[d],ny=y+dy[d];
            if(nx<=n&&nx>=1&&ny<=m&&ny>=1&&(maps[nx][ny]=='#'||maps[nx][ny]=='.')){
                x=nx,y=ny;
                if(maps[nx][ny]=='.')ans++,maps[nx][ny]='#';
            }
            else d=(d+1)%4;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
