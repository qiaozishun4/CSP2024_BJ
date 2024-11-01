#include<bits/stdc++.h>
using namespace std;
char maps[1005][1005];
bool dis[1005][1005];
int ans;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        ans=1;
        memset(dis,false,sizeof(dis));
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        dis[x][y]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) cin>>maps[i][j];
        }for(int i=1;i<=k;i++){
            int nx=x+dx[d],ny=y+dy[d];
            if(nx<1||nx>n||ny<1||ny>m||maps[nx][ny]=='x') d=(d+1)%4;
            else{
                x=nx;
                y=ny;
                if(!dis[nx][ny]) ans++;
                dis[nx][ny]=true;
            }

        }cout<<ans<<endl;
    }
    return 0;
}
