#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int t,k,n,m,x,y,d,ans;
char adj[1005][1005];
bool v[100][1005];
int dx[5]={0,1,0,-1};
int dy[5]={1,0,-1,0};
void dfs(int x,int y,int d,int st){
    int step=st;
    //cout<<endl<<"x="<<x<<" y="<<y<<" step="<<step;
    v[x][y]=1;
    for(int i=0;i<4;i++){
        if(step==k) return ;
        int dd=(d+i)%4;
        int nx=x+dx[dd],ny=y+dy[dd];
        if(nx>0&&nx<=n&&ny>0&&ny<=m){
            if(adj[nx][ny]=='.'){
                dfs(nx,ny,dd,step+1);
                return ;
            }
        }
        step++;
        //cout<<" step="<<step;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%d %d %d",&n,&m,&k);
        scanf("%d %d %d",&x,&y,&d);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>adj[i][j];
                v[i][j]=false;
            }
        }
        dfs(x,y,d,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(v[i][j]){
                    ans++;
                    //cout<<"i="<<i<<" j="<<j<<endl;
                }
            }
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
