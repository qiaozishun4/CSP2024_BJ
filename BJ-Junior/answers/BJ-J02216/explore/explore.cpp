#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k,ans;
int xx,yy,dd;
int nxt[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char mmap[1010][1010];
int vst[1010][1010];
void dfs(int x,int y,int d,int st){
    if(vst[x][y]==0){
        ans++;
        vst[x][y]=1;
    }
    if(st==0){
        cout<<ans<<endl;
        return;
    }
    int nx=x+nxt[d][0],ny=y+nxt[d][1];
    if(nx<=n&&nx>=1&&ny<=m&&ny>=1&&mmap[nx][ny]=='.'){
        dfs(nx,ny,d,st-1);
    }else{
        dfs(x,y,(d+1)%4,st-1);
    }
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>xx>>yy>>dd;
        memset(vst,0,sizeof(vst));
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mmap[i][j];
            }
        }
        dfs(xx,yy,dd,k);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
