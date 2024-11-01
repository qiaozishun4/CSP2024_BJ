#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d;
char a[1010][1010];
int fx[4]={0,1,0,-1};
int fy[4]={1,0,-1,0};
int bfs(int x,int y,int d,int k){
    int cnt=1,vis[1010][1010]={0};
    vis[x][y]=1;
    for(int i=1;i<=k;i++){
        int nx=x+fx[d],ny=y+fy[d];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]!='x'){
            if(vis[nx][ny]==0)cnt++;
            x=nx,y=ny;
            vis[nx][ny]=1;
        }else{
            d=(d+1)%4;
        }
    }
    return cnt;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        cout<<bfs(x,y,d,k)<<endl;
    }
    return 0;
}

