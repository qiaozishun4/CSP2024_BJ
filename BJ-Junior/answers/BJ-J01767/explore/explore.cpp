#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,ans=0;
char a[1005][1005];
int vis[1005][1005]={};
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int f(){
    ans=0;
    for(int i=1;i<=k;i++){
        if(vis[x][y]==0) ans++;
        vis[x][y]=1;
        int fx=x+dx[d];
        int fy=y+dy[d];
        if(fx>=1&&fx<=n&&fy>=1&&fy<=m&&a[fx][fy]!='x') x=fx,y=fy;
        else d=(d+1)%4;
    }
    if(vis[x][y]==0) ans++;
    return ans;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int l=1;l<=t;l++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                vis[i][j]=0;
            }
        }
        cout<<f();
    }
    return 0;
}
