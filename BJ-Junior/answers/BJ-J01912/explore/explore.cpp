#include<bits/stdc++.h>
using namespace std;
char map1[int(1e3)+5][int(1e3)+5]={};
long long t,n,m,sum=0,x,y,k,d,vis[int(1e3)+5][int(1e3)+5]={};
int a[4][2]={{1,0},{0,1},{-1,0},{0,-1}}
void dfs(int sx,int sy){
    if(k==0){
        return;
    }
    vis[sx][sy]=1;
    for(int i=0;i<=3;d=(d+1)%4,i++){
        int ex=a[d][1];
        int ey=a[d][2];
        if(1<=ex && ex<=n && 1<=ey && ey<=m && map1[ex][ey]=='.'){
            k--;
            dfs(ex,ey);
        }
    }

}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                vis[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;i=j<=m;j++){
                cin>>map1[i][j];
            }
        }
        k--;
        dfs(x,y);
        sum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==1){
                    sum++;
                }
            }
        }
        cout<<sum;
    }


    return 0;
}
