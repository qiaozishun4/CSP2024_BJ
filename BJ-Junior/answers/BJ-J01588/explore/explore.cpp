#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e3+5;
const int MAXK=1e6+5;
int t,m,n,k,x,y,d0;
char a[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dx[5]={0,1,0,-1},dy[5]={1,0,-1,0};
bool chk(int p,int q){
    if(1<=p&&p<=n&&1<=q&&q<=m&&a[p][q]=='.') return 1;
    return 0;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d0;
        memset(vis,0,sizeof(vis));
        vis[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        while(k--){
            if(chk(x+dx[d0],y+dy[d0])){
                x+=dx[d0];
                y+=dy[d0];
                vis[x][y]=1;
            }else d0=(d0+1)%4;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
