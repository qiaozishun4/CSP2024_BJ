#include<bits/stdc++.h>
using namespace std;

int T,n,m,k,xx,yy,d0,vis[1010][1010];
string sv_in[1010];
char mp[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        cin>>xx>>yy>>d0;
        for(int i=1;i<=n;i++){
            cin>>sv_in[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                mp[i][j]=sv_in[i][j-1];
            }
        }
        vis[xx][yy]=1;
        for(int step=1;step<=k;step++){
            int nx=xx,ny=yy;
            if(d0==0)    ny++;
            else if(d0==1)  nx++;
            else if(d0==2)  ny--;
            else    nx--;
            if(nx<1||nx>n||ny<1||ny>m||mp[nx][ny]=='x'){
                d0=(d0+1)%4;
            }
            else{
                xx=nx;yy=ny;
            }
            vis[xx][yy]=1;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans+=vis[i][j];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}