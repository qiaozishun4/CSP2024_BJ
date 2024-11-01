#include <bits/stdc++.h>
using namespace std;
char mp[1010][1010];
bool vis[1010][1010];
int mx[4]={0,1,0,-1};
int my[4]={1,0,-1,0};
int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t; cin>>t;
    while (t--){
        memset(vis,0,sizeof(vis));
        int n,m,k,x,y,p;
        cin>>n>>m>>k>>x>>y>>p;
        for (int i=1; i<=n; i++){
            scanf("%s",mp[i]+1);
        }while (k--){
            vis[x][y]=1;
            int nx=x+mx[p];
            int ny=y+my[p];
            if (nx<1||ny<1||nx>n||ny>m){
                p=(p+1)%4; continue;
            }if (mp[nx][ny]=='x'){
                p=(p+1)%4; continue;
            }vis[nx][ny]=1;
            x=nx; y=ny;
        }int cnt=0;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (vis[i][j]) cnt++;
            }
        }cout<<cnt<<"\n";
    }return 0;
}
