#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000+2;
int ans=0,t,n,m,k,x,y,nx,ny,d,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char a[MAXN][MAXN];
bool u[MAXN][MAXN];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                u[i][j]=0;
            }
        for(int i=1;i<=k;i++){
            ans+=(!u[x][y]);
            u[x][y]=1;
            nx=x+dx[d];ny=y+dy[d];
            if(nx>n||nx<1||ny>m||ny<1||a[nx][ny]=='x'){
                d=(d+1)%4;
                continue;
            }
            x=nx;y=ny;
        }
        ans+=(!u[x][y]);
        cout<<ans<<endl;
    }
    return 0;
}
