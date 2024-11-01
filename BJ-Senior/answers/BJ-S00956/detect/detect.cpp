#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
    int l,r;
    bool operator < (const node &rhs)const{
        return r<rhs.r;
    }
}a[N];
int _;
int n,m,k,L,V;
int p[N];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&_);
    while(_--){
        scanf("%d%d%d%d",&n,&m,&L,&V),k=0;
        for(int i=1;i<=n;i++){
            double d,v,dv;
            scanf("%lf%lf%lf",&d,&v,&dv);
            if(dv>0){
                double x=((V+0.000001)*(V+0.000001)-v*v)/(2*dv);
                a[++k]=(node){ceil(max(d,d+x)),L};
            }
            else if(dv<0){
                if(v<=V) continue;
                double x=((V+0.000001)*(V+0.000001)-v*v)/(2*dv);
                a[++k]=(node){(int)d,floor(min(d+x,(double)L))};
            }
            else{
                if(v<=V) continue;
                a[++k]=(node){d,L};
            }
        }
        for(int i=1;i<=m;i++) scanf("%d",&p[i]);
        int ans1=0;
        for(int i=1;i<=k;i++){
            a[i].l=lower_bound(p+1,p+1+m,a[i].l)-p;
            a[i].r=upper_bound(p+1,p+1+m,a[i].r)-p-1;
            if(a[i].l<=a[i].r) ans1++;
        }
        printf("%d ",ans1);
        sort(a+1,a+1+k);
        int lst=0,ans2=0;
        for(int i=1;i<=k;i++){
            if(a[i].l>a[i].r) continue;
            if(a[i].l>lst) ans2++,lst=a[i].r;
        }
        printf("%d\n",m-ans2);
    }
    return 0;
}
