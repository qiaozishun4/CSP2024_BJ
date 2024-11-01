#include<bits/stdc++.h>
using namespace std;
int T,a[1010][1010],vis[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        memset(a,0,sizeof a);
        memset(vis,0,sizeof vis);
        int n,m,k,x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++){
                if(s[j]=='.')a[i][j+1]=1;
            }
        }
        vis[x][y]=1;
        while(k--){
            int nx=0,ny=0;
            if(d==0){
                nx=x,ny=y+1;
            }
            else if(d==1){
                nx=x+1,ny=y;
            }
            else if(d==2){
                nx=x,ny=y-1;
            }
            else if(d==3){
                nx=x-1,ny=y;
            }
            if(a[nx][ny]==1)x=nx,y=ny,vis[nx][ny]=1;
            else d=(d+1)%4;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==1)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
