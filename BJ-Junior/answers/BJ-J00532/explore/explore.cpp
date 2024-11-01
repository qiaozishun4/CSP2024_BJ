#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int T,dx[5]={0,1,0,-1},dy[5]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        int n,m,k,x,y,d,ans=0;
        bool mp[N][N],g[N][N];
        cin>>n>>m>>k>>x>>y>>d;
        
        for(int i=1;i<=n;i++) mp[i][0]=mp[i][m+1]=0;
        for(int j=1;j<=m;j++) mp[0][j]=mp[n+1][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char c;
                cin>>c;
                if(c=='.'){
                    mp[i][j]=1;
                }
                else{
                    mp[i][j]=0;
                }
                g[i][j]=0;
            }
        }
        g[x][y]=1;
        for(int _=1;_<=k;_++){
            if(mp[x+dx[d]][y+dy[d]]==0){
                d=(d+1)%4;
            }
            else{
                x=x+dx[d];
                y=y+dy[d];
                g[x][y]=1;
            }
            
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(g[i][j]==1){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}