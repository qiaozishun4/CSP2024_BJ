#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d;
char a[1005][1005];
int dx[15]={0,1,0,-1},dy[15]={1,0,-1,0};
bool f[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        memset(f,false,sizeof(f));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        f[x][y]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        while(k--){
            int nx=x+dx[d],ny=y+dy[d];
            if(nx<=n&&nx>=1&&ny<=m&&ny>=1&&a[nx][ny]=='.'){
                x=nx,y=ny;
                f[x][y]=true;
            }else{
                d=(d+1)%4;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(f[i][j]==true){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}

