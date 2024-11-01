#include <bits/stdc++.h>
#define il inline
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
il int read(){
    int x=0,c=getchar(),f=0;
    while(!isdigit(c)) f|=c=='-',c=getchar();
    while(isdigit(c)) x=x*10+c-48,c=getchar();
    return f?-x:x;
}
const int N=1e5+5,M=1e6+5,oo=1e9;const double inf=1e9,eps=1e-9;
int T,n,m,L,V,b[N],cnt,s[M],k,ans,f[N],mx[N];pii c[N];
struct node{
    int p,v,a,l,r;
    il node(){p=v=a=l=r=0;}
}a[N];
int q[N],hh,tt;
int x,y,z;double u,v,w,p,l,r;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&n,&m,&L,&V);k=ans=0;
        for(int i=1;i<=n;++i) a[i].p=read(),a[i].v=read(),a[i].a=read(),a[i].l=a[i].r=0;
        for(int i=1;i<=m;++i) b[i]=read();
        sort(b+1,b+1+m);
        for(int i=1;i<=n;++i){
            p=a[i].p,v=a[i].v,u=a[i].a,l=r=0;
            if(a[i].a>0){
                if(a[i].v>V) l=a[i].p,r=L;
                else{
                    u=1.00*(V-a[i].v)/a[i].a;
                    w=1.00*a[i].v*u+0.5*a[i].a*u*u+eps;
                    l=ceil(1.00*a[i].p+w),r=L;
                    //if(1.00*a[i].v*a[i].v+2.00*a[i].a*(l-a[i].p)<=1.00*V+1)
                    //    l+=1,puts("*");
                }
            }
            else if(a[i].a==0){
                if(a[i].v<=V) l=inf,r=0;
                else l=a[i].p,r=L;
            }
            else{
                if(a[i].v<=V) l=inf,r=0;
                else{
                    u=1.00*(V-a[i].v)/a[i].a;
                    w=1.00*a[i].v*u+0.5*a[i].a*u*u-eps;
                    r=min(floor(a[i].p+w),1.00*L),l=a[i].p;
                    //if(1.00*a[i].v*a[i].v+2.00*a[i].a*(r-a[i].p)<=1.00*V+eps) r-=1;
                }
            }
            l=max(l,0.0);
            a[i].l=int(l),a[i].r=int(r);
        }
        for(int i=0;i<M;++i) s[i]=0;
        for(int i=1;i<=m;++i) ++s[b[i]];
        for(int i=1;i<M;++i) s[i]+=s[i-1];
        k=0;
        for(int i=1;i<=n;++i){
            if(a[i].l>a[i].r) continue;
            if(s[a[i].r]-s[a[i].l-1]) c[++k]={a[i].l,a[i].r};
        }
        for(int i=0;i<=m;++i) mx[i]=0;
        for(int i=1;i<=k;++i){
            x=c[i].fi,y=c[i].se;
            x=lower_bound(b+1,b+1+m,x)-b;
            y=upper_bound(b+1,b+1+m,y)-b-1;
            mx[y]=max(mx[y],x);
        }
        for(int i=1;i<=m;++i) mx[i]=max(mx[i-1],mx[i]);
        f[0]=0,hh=1,tt=0,q[++tt]=0;
        for(int i=1;i<=m;++i){
            f[i]=oo;
            while(hh<=tt && q[hh]<mx[i-1]) ++hh;
            if(hh<=tt) f[i]=f[q[hh]]+1;
            while(hh<=tt && f[i]<=f[q[tt]]) --tt;
            q[++tt]=i;
            //for(int j=i-1;j>=0 && j>=mx[i-1];--j) f[i]=min(f[i][1],f[j][1]+1);
        }
        x=oo;for(int i=mx[m];i<m;++i) x=min(x,f[i]);
        ans=min(x,f[m]);
        //for(int i=1;i<=m;++i) printf("%d %d\n",mx[i],i);puts("");
        //for(int i=1;i<=k;++i) printf("%d %d\n",c[i].fi,c[i].se);
        //printf("*** %d %d\n",m,ans);
        printf("%d %d\n",k,m-ans);
    }


    return 0;
}
