#include<bits/stdc++.h>
using namespace std;
int t,n,m,s,x,y,zt;
int ax[10]={0,1,0,-1},ay[10]={1,0,-1,0};
bool vis[1005][1005];
char cnt[1005][1005];
void dfs(int dx,int dy,int type,int sum){

    vis[dx][dy]=true;
    if(sum==0)return;
    type%=4;
    if(dx+ax[type]<1||dx+ax[type]>n||dy+ay[type]<1||dy+ay[type]>m||cnt[dx+ax[type]][dy+ay[type]]=='x'){dfs(dx,dy,type+1,sum-1);}
    else{dfs(dx+ax[type],dy+ay[type],type,sum-1);}
}int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m>>s>>x>>y>>zt;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                cin>>cnt[j][k];
                vis[j][k]=false;
            }
        }dfs(x,y,zt,s);
        int ans=0;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                ans+=vis[j][k];
            }
        }cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
