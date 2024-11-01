#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool vis[1003][1003];
char a[1003][1003];
int maxx=-1;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void dfs(int x,int y,int step,int pre,int to){
    maxx=max(maxx,pre);
    if(step==k){
        //maxx=max(maxx,pre);
        return;
    }
    int nx=dx[to]+x;
    int ny=dy[to]+y;
    //cout<<nx<<" "<<ny<<endl;
    if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]=='.'&&!vis[nx][ny]){
        vis[nx][ny]=1;
        dfs(nx,ny,step+1,pre+1,to);
        //vis[nx][ny]=0;
    }else{
        //cout<<1;
        int tt=to+1;
        if(tt==4) tt=0;
        dfs(x,y,step+1,pre,tt);
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        memset(a,' ',sizeof(a));
        cin>>n>>m>>k;
        int fx,fy,fd;
        cin>>fx>>fy>>fd;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--)
                a[i][j]=a[i][j-1];
        }
        dfs(fx,fy,0,1,fd);
        cout<<maxx<<endl;
        maxx=-1;
    }
    return 0;
}
