#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
char a[1010][1010];
bool vis[1010][1010];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void dfs(int x,int y,int d,int k){
    vis[x][y]=1;
    if(k==0)return;
    int nx=x+dx[d],ny=y+dy[d];
    bool inx=nx>=1&&nx<=n&&ny>=1&&ny<=m;
    if(inx&&a[nx][ny]=='.')dfs(nx,ny,d,k-1);
    else dfs(x,y,(d+1)%4,k-1);
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        for(int i=0;i<=1005;i++){
            for(int j=0;j<=1005;j++){
                vis[i][j]=0;
            }
        }
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        dfs(x,y,d,k);
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j])cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}