#include <bits/stdc++.h>
#define il inline
using namespace std;
typedef long long ll;
il void cmax(ll &x,ll y){x=x>y?x:y;}
il int read(){
    int x=0,c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) x=x*10+c-48,c=getchar();
    return x;
}
const int N=2e5+5;const ll inf=1e18;
int T,n,m,a[N],b[N];ll f[N][2],s[N],g[N],t1[N],t2[N];
il void add1(int x,ll v){while(x<=m) cmax(t1[x],v),x+=(x&-x);}
il void add2(int x,ll v){while(x) cmax(t2[x],v),x-=(x&-x);}
il ll get1(int x){ll ret=-inf;while(x) cmax(ret,t1[x]),x-=(x&-x);return ret;}
il ll get2(int x){ll ret=-inf;while(x<=m) cmax(ret,t2[x]),x+=(x&-x);return ret;}
int x,y,z;ll u,v,w;
int main(){
    //freopen("color.in","r",stdin);
   // freopen("color.out","w",stdout);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i) a[i]=read(),b[i]=a[i];
        sort(b+1,b+1+n);m=unique(b+1,b+1+n)-b-1;
        for(int i=1;i<=n;++i) a[i]=lower_bound(b+1,b+1+m,a[i])-b;
        for(int i=1;i<=n;++i) s[i]=s[i-1]+1ll*b[a[i]]*(a[i]==a[i-1]);
        for(int i=1;i<=m;++i) g[i]=-inf,t1[i]=t2[i]=-inf;
        f[1][0]=0ll,f[1][1]=0ll;
        for(int i=2;i<=n;++i){
            f[i][0]=max(f[i-1][0],f[i-1][1]);
            f[i][1]=max(f[i-1][0],f[i-1][1])+1ll*b[a[i]]*(a[i]==a[i-1]);
            /*for(int j=1;j<i-1;++j){
                cmax(f[i][0],f[j+1][0]+s[i-1]-s[j+1]+1ll*b[a[i]]*(a[i]==a[j]));
            }*/
            cmax(f[i][0],s[i-1]+g[a[i]]+1ll*b[a[i]]);
            cmax(f[i][0],s[i-1]+get1(a[i]-1));
            cmax(f[i][0],s[i-1]+get2(a[i]+1));
            //for(int j=1;j<=m;++j) if(a[i]!=j) cmax(f[i][0],s[i-1]+g[j]);
            w=f[i][0]-s[i];
            cmax(g[a[i-1]],w);
            add1(a[i-1],w),add2(a[i-1],w);
            //printf("** %d %lld %lld\n",i,f[i][0],f[i][1]);
        }
        printf("%lld\n",max(f[n][0],f[n][1]));
    }


    return 0;
}
