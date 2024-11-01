#include<bits/stdc++.h>
using namespace std;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int t;
char a[1005][1005];
int vis[1005][1005];
int ans=0;
int n,m,k,x,y,d;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        memset(vis,1,sizeof(vis));
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int z=1;z<=m;z++){
                cin>>a[j][z];
            }
        }
        ans++;
        for(int j=1;j<=k;j++){

            int tx=x+dir[d][0];
            int ty=y+dir[d][1];
            if( tx>=1 && tx<=n && ty>=1 && ty<=m && a[tx][ty]=='.'){
                if(vis[tx][ty]){
                    ans++;
                    vis[tx][ty]=0;
                }
                x=tx;
                y=ty;
            }
            else{

                d=(d+1)%4;
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}