#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 3005
#define MAXM 1000005
#define INF 0x7f7f7f7f
int t,n,m,L,V;
struct car{
    int d,v,a;
}x[MAXN];
int p[MAXN];
bool vis[MAXN],q[MAXN][MAXN];
int r,mx;
void dfs(int now,int k,int o){
    if(now==m+1){
        if(k==r)mx=max(mx,m-o);
        return ;
    }
    bool s[MAXN];
    int _k=k;
    for(int i=1;i<=n;i++){
        s[i]=vis[i];
        if(vis[i])continue;
        if(q[now][i]){
            k++;
            vis[i]=1;
        }
    }
    dfs(now+1,k,o+1);
    for(int i=1;i<=n;i++)vis[i]=s[i];
    dfs(now+1,_k,o);
    return ;
}
void work(){
    memset(q,0,sizeof(q));
    memset(vis,0,sizeof(vis));
    mx=0;r=0;
    for(int i=1;i<=m;i++){
        int d=p[i];
        for(int j=1;j<=n;j++){
            if(x[j].d>d)continue;
            if(x[j].v*x[j].v+2*x[j].a*(d-x[j].d)<0)continue;
            double _v=sqrt(x[j].v*x[j].v+2*x[j].a*(d-x[j].d));
            if(_v>V){
                q[i][j]=1;
                //printf("%d,%d\n",i,j);
                if(!vis[j]){
                    vis[j]=1;
                    r++;
                }
            }
        }
    }
    memset(vis,0,sizeof(vis));
    dfs(1,0,0);
    cout<<r<<' '<<mx<<endl;
    return ;
}
void init(){
    cin>>t;
    while(t--){
        memset(x,0,sizeof(x));
        memset(p,0,sizeof(p));
        int s=0;
        cin>>n>>m>>L>>V;
        for(int i=1,u,v,w;i<=n;i++){
            cin>>u>>v>>w;
            x[i]=(car){u,v,w};
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        work();
    }
    return ;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    init();
    return 0;
}