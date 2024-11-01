#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int f[10][5]={{0,1},{1,0},{0,-1},{-1,0}};
int n,m,s;
char a[N][N];
bool b[N][N];
bool check(int x,int y){
    if((x<1)||(x>n)||(y<1)||(y>m)){
        return 0;
    }
    return (a[x][y]=='.');
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int x,y,d,nx,ny;
        scanf("%d%d%d",&n,&m,&s);
        scanf("%d%d%d",&x,&y,&d);
        for(int i=1;i<=n;++i){
            scanf("%s",a[i]+1);
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                b[i][j]=0;
            }
        }
        b[x][y]=1;
        while(s--){
            nx=x+f[d][0];
            ny=y+f[d][1];
            if(check(nx,ny)){
                x=nx;
                y=ny;
            }else{
                d=(d+1)%4;
            }
            b[x][y]=1;
        }
        int ans=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                ans+=b[i][j];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}