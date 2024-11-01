#include <bits/stdc++.h>
using namespace std;
int dx[10]{0,1,0,-1},dy[10]{1,0,-1,0};
char ch[1005][1005];
bool v[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;scanf("%d",&t);
    for(int _=1;_<=t;++_){
        memset(v,0,sizeof(v));
        int n,m,k,x,y,d,c=0;scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j)cin >> ch[i][j];
        }
        v[x][y]=1;
        for(int i=1;i<=k;++i){
            int nx=x+dx[d],ny=y+dy[d];
            if(nx>0&&nx<=n&&ny>0&&ny<=m&&ch[nx][ny]!='x'){
                x=nx;
                y=ny;
                v[x][y]=1;
            }
            else d=(d+1)%4;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j)c+=v[i][j];
        }
        printf("%d\n",c);
    }
    return 0;
}