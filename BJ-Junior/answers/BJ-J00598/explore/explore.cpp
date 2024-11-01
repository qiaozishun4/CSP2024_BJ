#include<bits/stdc++.h>
using namespace std;
int T;
const int N=1005;
char a[N][N];
bool vis[N][N];
int n,m,k; //n,m maps;k steps
int x,y,d;
int cnt;
int main(){

    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        cnt=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                vis[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        vis[x][y]=1;
        while(k--){
            int nx=x,ny=y;
            if(d==0) ny++;
            else if(d==1) nx++;
            else if(d==2) ny--;
            else if(d==3) nx--;
            if(nx<1 || nx>n || ny<1 || ny>m){
                d=(d+1)%4;
                continue;
            }
            if(a[nx][ny]=='.'){
                x=nx,y=ny;
                vis[x][y]=1;
            } else d=(d+1)%4;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]) cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;

}
