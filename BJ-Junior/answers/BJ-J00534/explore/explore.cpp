#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d;
char a[1005][1005];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void f(int t){
    if(t==k) return;
    int nx=x+dx[d],ny=y+dy[d];
    if(nx<1 || ny<1 || nx>n || ny>m || a[nx][ny]='x'){
        d=(d+1)%4;
        f(t+1);
        return;
    }
    x=nx;
    y=ny;
    a[x][y]='z';
    f(t+1);
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    scanf("%d ",&T);
    while(T--){
        scanf(" %d %d %d %d %d %d ",&n,&m,&k,&x,&y,&d);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf(" %c ",&a[i][j]);
            }
        }
        a[x][y]='z';
        f(0);
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]=='z') cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
