#include<bits/stdc++.h>
using namespace std;
#define pt printf
#define fr(i,a,b) for(int i(a);i<=b;i++)
#define rf(i,a,b) for(int i(a);i>=b;i--)
#define eb emplace_back
#define pii pair<int,int>
#define file(f1,f2) if(f1!="")freopen(f1,"r",stdin);if(f2!="")freopen(f2,"w",stdout);
template<typename A,typename...B>inline void rd(A&x,B&...y) {
    char ch;bool f=0;
    while(!isdigit(ch=getchar()))if(ch=='-')f=1;
    x=0;do{x=(x<<1)+(x<<3)+(ch^48);}while(isdigit(ch=getchar()));
    if(f)x=-x;
    if constexpr(sizeof...(y))rd(y...);
}
const int N=1e3+33;
char mp[N][N];
bool vis[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
signed main(){
    file("explore.in","explore.out");
    int t;
    rd(t);
    while(t--){
        int n,m,k;
        rd(n,m,k);
        fr(i,1,n)fr(j,1,m)vis[i][j]=0;
        int x,y,d;
        rd(x,y,d);
        fr(i,1,n){
            scanf("%s",mp[i]+1);
            assert(strlen(mp[i]+1)==m);
        }
        vis[x][y]=1;
        fr(_,1,k){
            int nx=x+dx[d],ny=y+dy[d];
            if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&mp[nx][ny]=='.'){
                x=nx,y=ny;
            }else{
                d=(d+1)%4;
            }
            vis[x][y]=1;
        }
        int ans=0;
        fr(i,1,n)fr(j,1,m)ans+=vis[i][j];
        pt("%d\n",ans);
    }
    return 0;
}
