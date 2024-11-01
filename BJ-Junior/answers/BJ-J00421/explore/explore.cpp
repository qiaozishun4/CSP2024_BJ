#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
const int N = 1010;
int t,n,m,k,x,y,d,cnt;
char a[N][N];
bool f[N][N];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        for(int i = 1;i <= n;i++){
            scanf("%s",a[i]+1);
        }
        memset(f,false,sizeof(f));
        f[x][y]=true;
        cnt=1;
        while(k--){
            int tx=x+dx[d];
            int ty=y+dy[d];
            if(a[tx][ty]!='x'&&tx>=1&&tx<=n&&ty>=1&&ty<=m){
                if(!f[tx][ty]) cnt++;
                f[tx][ty]=true;
                x=tx;
                y=ty;
            }else{
                d=(d+1)%4;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
