#include<bits/stdc++.h>
using namespace std;
const int N=1e3 +  7;
const int dx[4]{0,1,0,-1};
const int dy[4]{1,0,-1,0};
char a[N][N];
int vis[N][N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;++i){
        int n,m,k,x,y,d,ans=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;++j){
            for(int l=1;l<=m;++l){
                cin>>a[j][l];
            }
        }
        for(int j=1;j<=k;++j){
            int nx=x+dx[d],ny=y+dy[d];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]=='.'){
                x=nx;
                y=ny;
                if(!vis[x][y]){
                    ++ans;
                    vis[x][y]=1;
                }
            }
            else d=(d+1)%4;
        }
        cout<<ans<<'\n';
        for(int j=1;j<=n;++j){
            for(int l=1;l<=m;++l){
                vis[j][l]=0;
            }
        }
    }
    return 0;
}