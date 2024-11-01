#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int T,n,m,l,v,p[N];
//pi!=pj (i!=j)
struct node{
    int d,v,a;
    int l,r;
}a[N];
bool cmp(node x,node y){
    return x.l<y.l;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&n,&m,&l,&v);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].d,&a[i].v,&a[i].a);
            a[i].l=a[i].r=0;
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&p[i]);
        }
        sort(p+1,p+m+1);
        //v1=sqrt(v0*v0+2*a*s);
        int ans1=0;
        for(int i=1;i<=n;i++){
            if(p[m]<a[i].d) continue;
            int p1=lower_bound(p+1,p+m+1,a[i].d)-p;
            if(a[i].a<0){
                int l=p1,r=m,ret=0;
                while(l<=r){
                    int mid=l+(r-l)/2;
                    int s=p[mid]-a[i].d;
                    double v1=sqrt(a[i].v*a[i].v+2*a[i].a*s);
                    if(v1>v) ret=mid,l=mid+1;
                    else r=mid-1;
                }
                if(!ret) continue;
                ans1++;
                a[i].l=p1,a[i].r=ret;
            }else if(a[i].a==0){
                if(a[i].v<=v) continue;
                ans1++;
                a[i].l=p1,a[i].r=m;
            }else{
                int l=p1,r=m,ret=0;
                while(l<=r){
                    int mid=l+(r-l)/2;
                    int s=p[mid]-a[i].d;
                    double v1=sqrt(a[i].v*a[i].v+2*a[i].a*s);
                    if(v1>v) ret=mid,r=mid-1;
                    else l=mid+1;
                }
                if(!ret) continue;
                ans1++;
                a[i].l=ret,a[i].r=m;
            }
        }
        int ans2=0;
        sort(a+1,a+n+1,cmp);
        for(int i=1,l=0,r=0;i<=n;i++){
            if(!a[i].l && !a[i].r) continue;
            if(!l && !r){
                ans2++;
                l=a[i].l,r=a[i].r;
            }else{
                if(r<a[i].l){
                    ans2++;
                    l=a[i].l,r=a[i].r;
                }else{
                    l=a[i].l;
                    r=min(r,a[i].r);
                }
            }
        }
        printf("%d %d\n",ans1,m-ans2);
    }
    return 0;
}

