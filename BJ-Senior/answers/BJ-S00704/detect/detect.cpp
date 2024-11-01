#include<bits/stdc++.h>
using namespace std;
const int N=30;
int t,n,m,L,V,l[N],r[N],p[N],e[N][N],s[N];
bool vis[N],mark[N];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        n=m=L=V=0;
        memset(p,0,sizeof p);
        memset(l,0,sizeof l);
        memset(r,0,sizeof r);
        memset(e,0,sizeof e);
        memset(vis,0,sizeof vis);
        memset(mark,0,sizeof mark);
        memset(s,0,sizeof s);
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for(int i=1,d,v,a;i<=n;i++){
            scanf("%d%d%d",&d,&v,&a);
            if(a==0&&v>V) l[i]=d,r[i]=L;
            if(a>0){
                if(v>V) l[i]=d,r[i]=L;
                else{
                    int x=(V*V-v*v)/(2*a);
                    if(d+x<=L) l[i]=d+x,r[i]=L;
                }
            }
            if(a<0&&v>V){
                int x=(v*v-V*V)/(2*(-a));
                l[i]=d,r[i]=min(L,d+x);
            }
        }
        for(int i=1;i<=m;i++){
            scanf("%d",p+i);
            for(int j=1;j<=n;j++)
                if(l[j]<=p[i]&&p[i]<=r[j]) e[i][++s[i]]=j,mark[j]=1;
        }
        int maxn=0;
        for(int i=1;i<=n;i++) maxn+=mark[i];
        int ans=10000;
        for(int i=0;i<=(1<<m)-1;i++){
            memset(vis,0,sizeof vis);
            int tot[22],u=i,cnt=1,k=0;
            memset(tot,0,sizeof tot);
            while(u){
                if(u&1) tot[++k]=cnt;
                u>>=1;cnt++;
            }
            cnt=0;
            for(int j=1;j<=k;j++)
                for(int ii=1;ii<=s[tot[j]];ii++){
                    int to=e[tot[j]][ii];
                    if(!vis[to]) vis[to]=1,cnt++;
                }
            if(cnt==maxn) ans=min(k,ans);
        }
        printf("%d %d\n",maxn,m-ans);
    }
    return 0;
}