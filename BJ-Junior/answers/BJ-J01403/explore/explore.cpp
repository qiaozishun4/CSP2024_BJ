#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d;
char c[1005][1005];
int v[1005][1005],ans,nx,ny,mx[4]={0,1,0,-1},my[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c[i][j];
            }
        }
        memset(v,0,sizeof(v));
        v[x][y]=1;
        ans=1;
        for(int i=1;i<=k;i++){
            nx=x+mx[d],ny=y+my[d];
            if(!nx||!ny||nx>n||ny>m||c[nx][ny]=='x') d=(d+1)%4;
            else x=nx,y=ny;
            if(!v[x][y]) ans++;
            v[x][y]=1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
