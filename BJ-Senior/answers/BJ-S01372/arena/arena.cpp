#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int,int> d[200007];
int ta[200007],a[200007],c[200007],ina[10],mb,vis[200007],nn,mm,tag[200007],tt,cc[200007],n,m,pw[200007];
vector<int> g,e;
int suan(){
    for(int i=1;i<=mm;i++) g.push_back(i),cc[i]=a[i];
    for(int i=nn+1;i<=mm;i++) g.push_back(i);
    e.clear();
    int cnt=0;
    while(g.size()>1){
        cnt++;
        e.clear();
        for(int i=0;i<g.size();i+=2){
            if(d[cnt][i/2+1]){
                if(cc[g[i+1]]>=cnt) e.push_back(g[i+1]);
                else e.push_back(g[i]);
            }else{
                if(cc[g[i]]>=cnt) e.push_back(g[i]);
                else e.push_back(g[i+1]);
            }
        }
        g=e;
    }
    // printf("%d\n",g[0]);
    return g[0];
}
void dfs(int u){
    if(u>mm){
        // for(int i=1;i<=mm;i++) printf("%d ",cc[i]);
        // printf("\n");
        tag[suan()]=1;
        return;
    }
    for(int i=1;i<=tt;i++){
        cc[u]=i;
        dfs(u+1);
    }
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&ta[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&c[i]);
    }
    pw[0]=1;
    int t;
    for(int i=1;;i++){
        pw[i]=pw[i-1]*2;
        t=i;
        if(pw[i]>n) break;
    }
    for(int i=1;i<=t;i++){
        for(int j=1;j<=pw[t-i];j++){
            int x;
            scanf("%1d",&x);
            d[i][j]=x;
        }
    }
    int T;
    scanf("%d",&T);
    while(T--){
        long long ans=0;
        for(int i=0;i<4;i++) scanf("%d",&ina[i]);
        for(int i=1;i<=n;i++) a[i]=ta[i]^ina[i%4];
        for(int qry=1;qry<=m;qry++){
        for(int i=1;;i++){
            if(pw[i]>=c[qry]){
                mm=pw[i];
                tt=i;
                break;
            }
        }
        nn=c[qry];
        // printf("%d %d\n",mm,nn);
        dfs(nn+1);
        long long sum=0;
        for(int i=1;i<=mm;i++){
            // printf("%d ",tag[i]);
            if(tag[i]) sum+=i;
        }
        // printf("%lld ",sum);
        ans^=((long long)qry*sum);
        for(int i=1;i<=mm;i++) tag[i]=0;
        }
        printf("%lld\n",ans);
    }
    return 0;
}