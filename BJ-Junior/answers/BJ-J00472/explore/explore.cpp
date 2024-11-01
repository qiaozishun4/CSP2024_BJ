#include<iostream>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,k,x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        char a[1005][1005]={};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        bool vis[1005][1005]={};
        vis[x][y]=true;
        int ans=1,head_to[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        for(int i=1;i<=k;i++){
            int xx=x+head_to[d][0],yy=y+head_to[d][1];
            if(1<=xx<=n&&1<=yy<=m&&a[xx][yy]=='.'){
                if(!vis[xx][yy]){
                    ans++;
                }
                vis[xx][yy]=true;
                x=xx;
                y=yy;
            }else{
                d=(d+1)%4;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}