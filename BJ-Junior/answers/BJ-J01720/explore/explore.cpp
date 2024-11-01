#include <iostream>
#define int long long
using namespace std;
char a[10001][10001];
int x1[10]={0,1,0,-1};
int y1[10]={1,0,-1,0};
int n,m,k,x0,y0,d0,ans;
void dfs(int x,int y,int d,int step){
    if(step>k) return ;
    int xx=x+x1[d],yy=y+y1[d];
    if(1<=x&&x<=n&&1<=y&&y<=m&&a[x][y]=='.'){
        ans++;
        a[x][y]='k';
    }
    if(1<=xx&&xx<=n&&1<=yy&&yy<=m&&a[xx][yy]!='x'){
        dfs(xx,yy,d,step+1);
    }else{
        dfs(x,y,(d+1)%4,step+1);
    }

}
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>x0>>y0>>d0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        ans=0;
        dfs(x0,y0,d0,0);
        cout<<ans<<endl;
    }
    fclose(stdin);
    (stdout);
    return 0;
}

