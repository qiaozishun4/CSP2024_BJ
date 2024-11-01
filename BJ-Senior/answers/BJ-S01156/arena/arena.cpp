#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN=2e5+5;
int N,M,T,K,L;
int b[MAXN],a[MAXN],c[MAXN],siz[30];
int p[30][MAXN];
int Big(int x)
{
    int t=1;
    while(t<x) t*=2;
    return t;
}
int Log(int x)
{
    int cnt=0;
    while(x>1) cnt++,x/=2;
    return cnt;
}
int k,l,nn;
LL ans=0;
bool yes[MAXN];
void dfs(int x)
{
    if(x==k-nn)
    {
        queue<int>q;
        for(int i=1;i<=k;i++) q.push(i);
        for(int i=1;i<=l;i++)
        {
            for(int j=1;j<=siz[i];j++)
            {
                int u=q.front();q.pop();
                int v=q.front();q.pop();
                if(p[i][j]==0)
                {
                    if(b[u]>=i) q.push(u);
                    else q.push(v);
                }
                else
                {
                    if(b[v]>=i) q.push(v);
                    else q.push(u);
                }
            }
        }
        yes[q.front()]=1;
        q.pop();
        return;
    }
    for(int i=0;i<=l;i++)
    {
        b[nn+1+x]=i;
        dfs(x+1);
        b[nn+1+x]=0;
    }
    return;
}
LL vis[MAXN];
LL Solve(int n)
{
    k=Big(n);
    l=Log(k);
    nn=n;
    if(l==0) return 1;
   // printf("%d %d %d\n",n,k,l);
    for(int i=1;i<=k;i++) yes[i]=0;
    siz[l]=1;
    for(int i=l-1;i>0;i--) siz[i]=siz[i+1]*2;
    dfs(0);
    LL res=0;
    for(int i=1;i<=k;i++) res+=1ll*i*1ll*yes[i];
  //  printf("[%d]\n",res);
    return res;
}
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    for(int i=1;i<=M;i++) scanf("%d",&c[i]);
    //for(int i=1;i<=N;i++) printf("(%d)",a[i]);
    K=Big(N);
    L=Log(K);
 //   printf("KL%d %d\n",K,L);
    if(L!=0)
    {
        siz[L]=1;
        for(int i=L-1;i>0;i--) siz[i]=siz[i+1]*2;
        for(int i=1;i<=L;i++)
        {
            for(int j=1;j<=siz[i];j++) scanf("%1d",&p[i][j]);
        }
    }
    scanf("%d",&T);
   // printf("T%d\n",T);
    int x[4];
    for(int i=0;i<4;i++) scanf("%d",&x[i]);
  //  printf("%d %d %d %d\n",x[0],x[1],x[2],x[3]);
    for(int i=1;i<=N;i++) a[i]^=x[i%4];
    for(int i=1;i<=N;i++) b[i]=a[i];
  //  for(int i=1;i<=N;i++) printf("(%d)",a[i]);
    for(int i=1;i<=M;i++) 
    {   
        if(!vis[c[i]])   vis[c[i]]=Solve(c[i]);
        ans^=1ll*i*vis[c[i]];
    }
    printf("%lld\n",ans);
    return 0;
}