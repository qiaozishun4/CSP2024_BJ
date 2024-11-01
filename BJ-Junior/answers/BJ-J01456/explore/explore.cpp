#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int vis[1005][1005],ans=1;
int n,m;
int da[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void dfs(int x,int y,int d,int k){
    if(k<=0){
        return;
    }
    int xx=x+da[d][0],yy=y+da[d][1];
    if(a[xx][yy]!='x'&&xx>=1&&xx<=n&&yy>=1&&yy<=m){
        if(vis[xx][yy]!=1){
            ans++;
            vis[xx][yy]=1;
        }
        dfs(xx,yy,d,k-1);
    }else{
        for(int i=d+1;i<d+5;i++){
            if(k!=0){
                k--;
            }
            if(k<=0){
                return;
            }
            xx=x+da[i%4][0],yy=y+da[i%4][1];
            if(a[xx][yy]=='.'&&xx<=n&&xx>=1&&yy<=m&&yy>=1){
                if(vis[xx][yy]!=1){
                    ans++;
                    vis[xx][yy]=1;
                }
                dfs(xx,yy,i%4,k-1);
                break;
            }
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        ans=1;
        int k;
        cin>>n>>m>>k;
        int sx,sy,sd;
        cin>>sx>>sy>>sd;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                vis[i][j]=0;
            }
        }
        vis[sx][sy]=1;
        dfs(sx,sy,sd,k);
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
