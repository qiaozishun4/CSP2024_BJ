#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k,d,e,r;
        cin>>n>>m>>k>>d>>e>>r;
        char s;
        bool c[n+1][m+1];
        bool vis[n+1][m+1];
        memset(vis,false,sizeof(vis));
        memset(c,false,sizeof(c));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>s;
                if(s=='.'){
                    c[i][j]=true;
                }
            }
        }
        int ans=0;
        vis[d][e]=true;
        while(k--){
            int nx,ny;
            if(r==0){
                nx=d;
                ny=e+1;
            }
            if(r==1){
                nx=d+1;
                ny=e;
            }
            if(r==2){
                nx=d;
                ny=e-1;
            }
            if(r==3){
                nx=d-1;
                ny=e;
            }
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&c[nx][ny]){
                d=nx;
                e=ny;
                vis[d][e]=true;
            }else{
                r=(r+1)%4;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
