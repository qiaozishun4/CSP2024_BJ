#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int maxn=1e5+10;
const double eps=1e-8;
int t,n,m,tot;
double L,V;
double p[maxn];
struct node{
    double d,v,a;
}c[maxn];
struct vertex{
    int l,r;
}ans[maxn];
inline void ipt(){
    tot=0;
    scanf("%lld%lld%lf%lf",&n,&m,&L,&V);
    for(int i=1;i<=n;i++)scanf("%lf%lf%lf",&c[i].d,&c[i].v,&c[i].a);
    for(int i=1;i<=m;i++)scanf("%lf",&p[i]);
}
inline double calv(double x,double y,double z){
    double dis=2.0*x*y+z*z;
    if(dis<0)return 0;
    return sqrt(dis);
}
inline bool check(int i,int mid){
    double nv=calv(c[i].a,p[mid]-c[i].d,c[i].v);
    // if(i==5)printf("%lld %lf\n",mid,nv);
    if(nv-V>eps)return true;
    return false;
}
inline void init(){
    for(int i=1;i<=n;i++){
        if(c[i].d>p[m])continue;
        int op=lower_bound(p+1,p+m+1,c[i].d)-p;
        if(fabs(c[i].a)<eps){
            if(c[i].v-V>eps){
                ans[++tot].l=op;
                ans[tot].r=m;  
                // printf("i = %lld %lld %lld\n",i,op,m);   
            }
        }
        else if(c[i].a>eps){
            int l=op,r=m,s=-1;
            while(l<=r){
                int mid=l+r>>1;
                if(check(i,mid)){
                    s=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            if(s==-1)continue;
            ans[++tot].l=s;
            ans[tot].r=m;
            // printf("i = %lld %lld %lld\n",i,s,m);
        }
        else {
            if(c[i].v-V<-eps)continue;
            int l=op,r=m,s=-1;
            while(l<=r){
                int mid=l+r>>1;
                if(check(i,mid)){
                    s=mid;
                    l=mid+1;
                }
                else r=mid-1;
            }
            if(s==-1)continue;
            ans[++tot].l=op;
            ans[tot].r=s;
            // printf("i = %lld %lld %lld\n",i,op,s);
        }
    }
}
inline bool cmp(vertex nx,vertex ny){return nx.r<ny.r;}
inline void solve(){
    printf("%lld ",tot);
    sort(ans+1,ans+tot+1,cmp);
    int cnt=1;
    if(tot==0)cnt=0;
    int op=ans[1].r;
    for(int i=2;i<=tot;i++){
        if(ans[i].l<=op)continue;
        ++cnt;
        op=ans[i].r;
    }
    printf("%lld\n",m-cnt);
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        ipt();
        init();
        solve();
    }

    return 0;
}