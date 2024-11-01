#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define round Rubyonly
#define end ylnoybuR
const int N=2005;
struct Edge {
    int u,v,next,id;
} e[N*10];
int head[200005],cur=0;
void add(int u,int v,int id) {
    cur++;
    e[cur]=Edge{u,v,head[u],id};
    head[u]=cur;
}
int T;
int s[N][N];
int l[N];
int depth[400005];
bool bfs(int rt,int round,int end) {
    memset(depth,0,sizeof(depth));
    queue<int> q;
    queue<int> prevId;
    q.push(rt);
    depth[rt]=0;
    while(!q.empty()) {
        int u=q.front();
        int pre=(prevId.empty()?114514191:prevId.front());
        prevId.pop();
        q.pop();
        if(depth[u]>=round) continue;
        //printf("In BFS:%d %d\n",u,depth[u]);
        for(int i=head[u];i;i=e[i].next) {
            if(e[i].id==pre) continue;
            int v=e[i].v;
            q.push(v);
            prevId.push(e[i].id);
            depth[v]=depth[u]+1;
            if(v==end&&depth[end]==round) return 1;
        }
    }
    return 0;
}
void solve() {
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++) {
        scanf("%d",&l[i]);
        for(int j=1;j<=l[i];j++) {
            scanf("%d",&s[i][j]);
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=l[i];j++) {
            for(int k=j+1;k<=j+m-1;k++) {
                add(s[i][j],s[i][k],i);
            }
        }
    }
    for(int i=1;i<=q;i++) {
        int r,c;
        scanf("%d%d",&r,&c);
        bool result=bfs(1,r,c);
        //printf("T=%d i=%d result=%d\n",T,i,result);
        if(result) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
}
int main() {
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&T);
    for(int i=1;i<=T;i++) solve();
    return 0;
}
