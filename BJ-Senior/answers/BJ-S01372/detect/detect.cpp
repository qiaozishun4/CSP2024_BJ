#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
struct cr{
    int d,v,a;
};
struct qj{
    int l,r;
};
bool cmp1(qj x,qj y){
    return x.r-x.l<y.r-y.l;
}
bool cc(qj x,qj y){
    return x.r<y.r;
}
qj q[100007],p[100007];
cr che[100007];
int ce[100007],n,m,L,V,tot,tr[800007];
int ef(int x){
    int ll=1,rr=m,ans=0;
    while(ll<=rr){
        int mid=(ll+rr)/2;
        if(ce[mid]<=x){
            ans=mid;
            ll=mid+1;
        }else rr=mid-1;
    }
    return ans;
}
int fe(int x){
    int ll=1,rr=m,ans=0;
    while(ll<=rr){
        int mid=(ll+rr)/2;
        if(ce[mid]>=x){
            ans=mid;
            rr=mid-1;
        }else ll=mid+1;
    }
    return ans;
}
void push_up(int u){
    tr[u]=max(tr[u*2],tr[u*2+1]);
}
void update(int u,int l,int r,int x,int k){
    if(l==r){
        tr[u]=max(tr[u],k);
        return;
    }
    int mid=(l+r)/2;
    if(x<=mid) update(u*2,l,mid,x,k);
    if(x>mid) update(u*2+1,mid+1,r,x,k);
    push_up(u);
}
int query(int u,int l,int r,int L,int R){
    if(L<=l && r<=R) return tr[u];
    int res=0,mid=(l+r)/2;
    if(L<=mid) res=query(u*2,l,mid,L,R);
    if(R>mid) res=max(res,query(u*2+1,mid+1,r,L,R));
    return res;
}
const long double eps=0.000001;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        tot=0;
        memset(tr,0,sizeof(tr));
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for(int i=1;i<=n;i++) scanf("%d%d%d",&che[i].d,&che[i].v,&che[i].a);
        for(int i=1;i<=m;i++) scanf("%d",&ce[i]);
        for(int i=1;i<=n;i++){
            long double d=che[i].d,v0=che[i].v,a=che[i].a;
            if(d>ce[m]) continue;
            if(a==0){
                int l;
                if(che[i].v>V){
                    l=ef(che[i].d);
                    q[++tot].l=l;
                    q[tot].r=m;
                    // printf("%d %d %d\n",i,l,m);
                }
                continue;
            }
            long double wy=((long double)V-v0)/a*v0+(((long double)V-v0)*((long double)V-v0)/2.0)/a+d;
            // printf("%Lf\n",wy);
            if(a>0){
                wy+=eps;
                long long s=ceil(wy);
                int l=fe(s);
                if(!l) continue;
                q[++tot].l=l;
                q[tot].r=m;
                // printf("%d %d %d\n",i,l,m);
            }else{
                wy-=eps;
                if(che[i].v<=V) continue;
                long long s=floor(wy);
                int r=ef(s);
                if(!r) continue;
                int l=fe(d);
                if(!l) continue;
                if(l>r) continue;
                q[++tot].l=l;
                q[tot].r=r;
                // printf("%d %d %d\n",i,l,r);
            }
        }
        printf("%d ",tot);
        sort(q+1,q+1+tot,cmp1);
        int cnt=0;
        for(int i=1;i<=tot;i++){
            if(query(1,1,m,1,q[i].r)>=q[i].l) continue;
            p[++cnt]=q[i];
            update(1,1,m,q[i].r,q[i].l);
        }
        sort(p+1,p+1+cnt,cc);
        int now=0,ans=0;
        for(int i=1;i<=cnt;i++){
            // printf("%d %d %d\n",p[i].l,p[i].r,ans);
            if(now>=p[i].l) continue;
            ans++;
            now=p[i].r;
            // printf("%d %d\n",p[i].l,p[i].r);
            // assert(p[i].l>=p[i-1].l);
        }
        printf("%d\n",m-ans);
    }
    return 0;
}
//haochi