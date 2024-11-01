//T2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline void print(ll x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar((x%10)^48);
}
const ll maxn=3e3+5;
ll dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},sx,sy,nx,ny,T,n,m,k,dir;
bool vis[maxn][maxn];
char gra[maxn][maxn];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    T=read();
    while(T--){
        memset(vis,0,sizeof(vis));
        memset(gra,0,sizeof(gra));
        n=read();m=read();k=read();
        sx=read();sy=read();dir=read();
        for(int i=1;i<=n;i++){
            scanf("%s",gra[i]+1);
        }
        vis[sx][sy]=true;
        for(int i=1;i<=k;i++){
            nx=sx+dx[dir];
            ny=sy+dy[dir];
            //debug

            while((nx<1 || nx>n || ny<1 || ny>m || gra[nx][ny]=='x') && i<=k){
                i++;
                dir=(dir+1)%4;
                nx=sx+dx[dir];
                ny=sy+dy[dir];
            }
            if(i>k)break;
            vis[nx][ny]=true;
           // print(nx);putchar(' ');print(ny);putchar('\n');
            sx=nx;
            sy=ny;
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j])ans++;
            }
        }
        print(ans);
        putchar('\n');
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
