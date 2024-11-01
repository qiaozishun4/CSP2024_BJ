#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,m,L;
int a[N],pp;
long long d[N],v[N],V;
double p[N];
int top,ans;
struct Range{
    int l,r;
    bool operator <(const Range &x)const{
        return l<x.l;
    }
    void init(){
        l=0,r=0;
    }
}R[N],now;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%lld",&n,&m,&L,&V);
        for(int i=1;i<=n;i++) scanf("%lld%lld%d",&d[i],&v[i],&a[i]);
        for(int i=1;i<=m;i++) scanf("%d",&pp),p[i]=pp;
        for(int i=1;i<=n;i++){
            int c1=lower_bound(p+1,p+1+m,1.0*d[i])-p;
            if(c1==m+1) continue;
            if(a[i]==0){
                if(v[i]>V)
                    R[++top]=(Range){c1,m};
            }
            else{
                double x=d[i]+(V*V-v[i]*v[i])/(2.0*a[i]);
                int c2;
                if(a[i]>0){
                    c2=upper_bound(p+1,p+1+m,x)-p;
                    if(v[i]>V) R[++top]=(Range){c1,m};
                    else
                        if(c2!=m+1) R[++top]=(Range){c2,m};
                }
                else{
                    c2=lower_bound(p+1,p+1+m,x)-p-1;
                    if(v[i]>V&&c1<=c2) R[++top]=(Range){c1,c2};
                }
            }
        }
        printf("%d ",top);
        sort(R+1,R+1+top);
        for(int i=1;i<=top;i++){
            if(R[i].l<=now.r){
                now.l=max(R[i].l,now.l);
                now.r=min(R[i].r,now.r);
            }
            else ans++,now=R[i];
        }
        printf("%d\n",m-ans);
        memset(d+1,0,sizeof(d));
        memset(a+1,0,sizeof(a));
        memset(v+1,0,sizeof(v));
        memset(p+1,0,sizeof(p));
        for(int i=1;i<=top;i++) R[i].init();
        top=ans=0;
        now.init();
    }
    return 0;
}
