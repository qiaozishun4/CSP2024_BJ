#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int T,n,m,k,x,y,d,nx,ny;
string e;
int a[1005][1005];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++){
        memset(a,1000005,0);
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;i++){
            cin>>e;
            for(int k=1;k<=m;k++){
                if(e[k]=='.')a[j][k]=1;
                else a[j][k]=0;
            }
        }
        for(int j=1;i<k;j++){
            a[x][y]='@';
            nx=x+dx[d],ny=y+dy[d];
            if(1<=nx && nx<=n && 1<=ny && ny<=m && a[nx][ny]!='x'){
                x=nx,y=ny;
            }
            else d=(d+1)%4;
        }
        a[x][y]='@';
    }
    return 0;
}
