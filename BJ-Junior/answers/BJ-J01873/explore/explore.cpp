#include <bits/stdc++.h>
using namespace std;
char mp[1005][1005];bool vis[1001][1001]={0};
int n,m,k,x,y,d,cnt;
int stepx[4]={0,1,0,-1},stepy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;cin>>t;
    while(t--){
        cnt=1;memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;cin>>x>>y>>d;
        vis[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)cin>>mp[i][j];
        }while(k--){
            if(x+stepx[d]>n||x+stepx[d]<1||y+stepy[d]>m||y+stepy[d]<1||mp[x+stepx[d]][y+stepy[d]]=='x')
                d=(d+1)%4;
            else{x+=stepx[d];y+=stepy[d];if(!vis[x][y])cnt++;vis[x][y]=1;}
        }cout<<cnt<<endl;
    }
}
