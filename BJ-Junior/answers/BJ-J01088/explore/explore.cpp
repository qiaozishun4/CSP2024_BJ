#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,k,a[N][N];
char t[N][N];
int x,y,d;
void go_on(){
    int nx,ny;
    if(d==0) nx=x,ny=y+1;
    else if(d==1) nx=x+1,ny=y;
    else if(d==2) nx=x,ny=y-1;
    else if(d==3) nx=x-1,ny=y;
    if(nx>=1 && nx<=n && ny>=1 && ny<=m && t[nx][ny]=='.') x=nx,y=ny,a[nx][ny]=1;
    else d=(d+1)%4;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(a,0,sizeof(a));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>t[i][j];
            }
        }
        a[x][y]=1;
        for(int i=1;i<=k;i++){
            //cout<<x<<" "<<y<<" "<<d<<endl;
            go_on();
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]==1) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
