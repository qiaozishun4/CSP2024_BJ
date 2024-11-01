#include<bits/stdc++.h>
using namespace std;
long long T,n,m,L,V,p[100005],ans;
struct st{
    long long l,r,id;
}cl[100005],cr[100005];
inline bool cmpl(st a,st b){
    return a.l<b.l;
}
inline bool cmpr(st a,st b){
    return a.r<b.r;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
        for(int b=1;b<=n;b++){
            long long d,v,a;
            scanf("%lld%lld%lld",&d,&v,&a);
            cl[b].l=cl[b].r=-1;
            if(!a){
                if(v>V){
                    cl[b].l=d;
                    cl[b].r=L;
                }
            }else if(a>0){
                if(v>V){
                    cl[b].l=d;
                    cl[b].r=L;
                }else{
                    cl[b].l=d+(V*V-v*v)/(2*a)+1;
                    cl[b].r=L;
                    if(cl[b].l>L)cl[b].l=cl[b].r=-1;
                }
            }else{
                if(v>V){
                    cl[b].l=d;
                    cl[b].r=d+(v*v-V*V)/(-2*a);
                    if((V*V-v*v)%(2*a)==0)cl[b].r--;
                    cl[b].r=min(cl[b].r,L);
                }
            }
        }
        for(int b=1;b<=m;b++)scanf("%lld",&p[b]);
        sort(p+1,p+1+m);
        for(int b=1;b<=n;b++){
            if(lower_bound(p+1,p+1+m,cl[b].l)-p<=m && p[lower_bound(p+1,p+1+m,cl[b].l)-p]<=cl[b].r)ans++;
            else cl[b].l=cl[b].r=-1;
            cr[b].l=cl[b].l;
            cr[b].r=cl[b].r;
            cr[b].id=b;
        }
        cout<<ans<<" ";
        sort(cr+1,cr+1+n,cmpr);
        long long i=n-ans+1;
        for(int b=i;b<=n;b++)cl[cr[b].id].id=b;
        sort(cl+1,cl+1+n,cmpl);
        ans=0;
        for(int b=i;b<=n;b++){
            if(cr[b].l==-1)continue;
            ans++;
            long long rb=p[upper_bound(p+1,p+1+m,cr[b].r)-p-1];
            while(i<=n && cl[i].l<=rb){
                cr[cl[i].id].l=-1;
                i++;
            }
        }
        cout<<m-ans<<"\n";
        ans=0;
    }
    return 0;
}
