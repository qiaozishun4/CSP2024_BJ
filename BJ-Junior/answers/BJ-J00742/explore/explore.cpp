#include<bits/stdc++.h>
using namespace std;
int T,a,d,k,m,n,tx,ty,x,y;
bool vi[1005][1005];
char ar[1005][1005];
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin),freopen("explore.out","w",stdout);
    scanf("%d\n",&T);
    while(T--){
        scanf("%d %d %d\n%d %d %d\n",&n,&m,&k,&x,&y,&d);
        memset(vi,0,sizeof(vi)),vi[x][y]=1,a=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)scanf("%c",&ar[i][j]);
            scanf("\n");
        }
        while(k!=0){
            tx=x+dx[d],ty=y+dy[d];
            if(tx>0&&tx<=n&&ty>0&&ty<=m&&ar[tx][ty]=='.'){
                if(!vi[tx][ty])vi[tx][ty]=1,a++;
                x=tx,y=ty;
            }
            else d=(d+1)%4;
            k--;
        }
        printf("%d\n",a);
    }
    return 0;
}
