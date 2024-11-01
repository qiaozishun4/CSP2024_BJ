#include <bits/stdc++.h>
using namespace std;

const int maxn=1005;

int t;

int n,m,k;
int x,y,d;
int a[maxn][maxn];
bool vis[maxn][maxn];

char z;//cin

int dx[]={0,1,0,-1},dy[]={1,0,-1,0};//d

int nx,ny;//now
int fx,fy;

int ans=1;

int main(){

    freopen("explore5.in","r",stdin);
    freopen("explore5.out","w",stdout);

    cin>>t;

    while(t--){
        cin>>n>>m>>k;
        cin>>fx>>fy>>d;

        ans=1;
        x=fx;y=fy;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                vis[i][j]=0;
                cin>>z;
                if(z=='x'){
                    a[i][j]=1;
                }else{
                    a[i][j]=0;
                }
            }
        }

        while(k--){
            nx=x+dx[d];
            ny=y+dy[d];
            if(a[nx][ny]==1){
                d=(d+1)%4;
            }else if(nx<=n&&nx>=1&&ny<=m&&ny>=1){
                x=nx;y=ny;
                if(vis[x][y]!=1){
                    ans++;
                    vis[x][y]=1;
                    //cout<<x<<" "<<y<<endl;
                }
            }else{
                d=(d+1)%4;
            }
        }
        if(vis[fx][fy]==1){
            ans--;
        }
        cout<<ans<<endl;
    }
    return 0;
}
