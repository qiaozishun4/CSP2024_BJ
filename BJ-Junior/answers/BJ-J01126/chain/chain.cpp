#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define sc second
#define fr first
#define mk make_pair
#define pb push_back
int read(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();return x*f;}
const int MAXN=200010,N=110,V=200000,MAXM=110;
int n,m,k,a[MAXN],nx[MAXN],ls[MAXN],cnt;
vector<int>s[MAXN];
vector<pii>g[MAXN];
struct DSU{
    int bg,ed;
    void init(int x){
        bg=cnt,ed=bg+x;cnt=ed;
        for(int i=bg;i<ed;i++)ls[i]=i-1,nx[i]=i+1;
        ls[bg]=-1;
        nx[ed-1]=-1;
    }
    void clear(int x){
        for(int i=bg;i<ed;i++)ls[i]=i-1,nx[i]=i+1;
        ls[bg]=-1;
        nx[ed-1]=-1;
    }
    int nxt(int x){
        return nx[x+bg]==-1?-1:nx[x+bg]-bg;
    }
    void del(int x){
        x+=bg;
        if(~ls[x])nx[ls[x]]=nx[x];
        if(~nx[x])ls[nx[x]]=ls[x];
    }
}D[MAXN];
int f[N][MAXN];
void dp(int t,int id,int x){
    int now=D[id].nxt(x);
    while(now-x+1<=k&&~now){
        if(f[t][s[id][now]]!=-1&&f[t][s[id][now]]!=id)f[t][s[id][now]]=0;
        else f[t][s[id][now]]=id;
        D[id].del(now);
        now=D[id].nxt(now);
    }
}
void slv(){
    n=read(),k=read(),m=read();
    cnt=0;
    for(int i=1;i<=n;i++){
        a[i]=read();
        for(int j=0;j<a[i];j++)s[i].pb(read());
        D[i].init(a[i]);
    }
    memset(f,-1,sizeof(f));
    f[0][1]=0;
    for(int i=1;i<=100;i++){
        for(int j=1;j<=n;j++){
            for(int k=a[j]-1;k>=0;k--)if(f[i-1][s[j][k]]!=-1&&f[i-1][s[j][k]]!=j){
                dp(i,j,k);
            }
        }
        for(int j=1;j<=n;j++)D[j].clear(a[j]);
    }
    while(m--){
        int r=read(),c=read();
        printf("%d\n",f[r][c]!=-1);
    }
    for(int i=1;i<=n;i++)s[i].clear();
}
signed main(){
    freopen("chain.in","r",stdin);freopen("chain.out","w",stdout);
    int _=read();while(_--)
    slv();
    fclose(stdin);fclose(stdout);
    return 0;
}