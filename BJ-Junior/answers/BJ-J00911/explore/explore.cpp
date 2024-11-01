#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
char ch[N][N];
bool vis[N][N];
long long ans;
int n,m,k,x_,y_,d_;
void dfs(int x,int y,int d,int step){
    if(vis[x][y]==0){
        ans++;
        vis[x][y]=1;
    }
    if(step==k){
        cout<<ans<<endl;
        return;
    }
    int dx,dy;
    if(d==0)dx=x,dy=y+1;
    else if(d==1)dx=x+1,dy=y;
    else if(d==2)dx=x,dy=y-1;
    else if(d==3)dx=x-1,dy=y;
    if(ch[dx][dy]!='x'&&dx>=1&&dx<=n&&dy>=1&&dy<=m)dfs(dx,dy,d,step+1);
    else dfs(x,y,(d+1)%4,step+1);
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        ans=0;
        cin>>n>>m>>k;
        cin>>x_>>y_>>d_;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
               cin>>ch[i][j];
         dfs(x_,y_,d_,0);
         for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
               vis[i][j]=0;
    }
    return 0;
}
