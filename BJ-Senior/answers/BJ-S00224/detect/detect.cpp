#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace FastIO{
    inline int read(){
        int x=0,f=1;
        char ch=getchar();
        while(ch>'9'||ch<'0'){
            if(ch=='-') f=-1;
            ch=getchar();
        }
        while(ch>='0'&&ch<='9'){
            x=(x<<1)+(x<<3)+ch-'0';
            ch=getchar();
        }
        return x*f;
    }
    inline void write(int x){
        if(x<0){
            x=-x;
            putchar('-');
        }
        if(x>9) write(x/10);
        putchar(x%10+'0');
    }
}
using FastIO::read;
using FastIO::write;
const int N=1e5+10,inf=2e18;
int cnt,tot,n,m,L,V,st[N],mx[N<<2];
double d[N],v[N],a[N],p[N];
struct node{
    int l,r;
    bool operator<(const node&b)const{
        if(l!=b.l) return l<b.l;
        else return r<b.r;
    }
}b[N],c[N];
double pd(int x,int id){
    double pl=p[id];
    double jl=d[x]-v[x]*v[x]/2.0/a[x];
    if(a[x]>=0) jl=inf;
/*    if(x==4){
        cout<<x<<" "<<jl<<" "<<pl<<" "<<pl-d[x]<<" "<<sqrt(v[x]*v[x]+2*a[x]*(pl-d[x]))<<endl;
    }*/
    if(jl<pl) return 0.0;
    if(pl<d[x]) return -1.0;
    double dis=pl-d[x];
    double newv=sqrt(v[x]*v[x]+2*a[x]*dis);
    return newv;
}
void modify(int p,int l,int r,int x,int y){
    if(l>x||r<x) return ;
    if(l==r){
        mx[p]=y;
        return ;
    }
    int mid=(l+r)/2;
    modify(p*2,l,mid,x,y);
    modify(p*2+1,mid+1,r,x,y);
    mx[p]=min(mx[p*2],mx[p*2+1]);
}
int query(int p,int l,int r,int x,int y){
    if(l>y||r<x) return inf;
    if(x<=l&&r<=y) return mx[p];
    int mid=(l+r)/2;
    return min(query(p*2,l,mid,x,y),query(p*2+1,mid+1,r,x,y));
}
void work(){
    cnt=tot=0;
    n=read(),m=read(),L=read(),V=read();
    for(int i=1;i<=n;i++){
        d[i]=read(),v[i]=read(),a[i]=read();
    }
    for(int i=1;i<=m;i++){
        p[i]=read();
    }
    sort(p+1,p+m+1);
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            if(v[i]>V){
                int l=1,r=m,ans=0;
                while(l<=r){
                    int mid=(l+r)/2;
                    if(p[mid]>=d[i]){
                        ans=mid;
                        r=mid-1;
                    }else l=mid+1;
                }
                if(ans!=0){
                    b[++cnt]={ans,m};
                 //   cout<<i<<" "<<ans<<" "<<m<<endl;
                }
            }
        }else if(a[i]>0){
            int l=1,r=m,ans=0;
            while(l<=r){
                int mid=(l+r)/2;
                if(pd(i,mid)>(V*1.0)){
                    ans=mid;
                    r=mid-1;
                }else l=mid+1;
            }
            if(ans!=0){
                b[++cnt]={ans,m};
             //   cout<<i<<" "<<ans<<" "<<m<<endl;
            }
        }else{
            if(v[i]<=V) continue;
            int l=1,r=m,ans=m+1,ans1=0;
            while(l<=r){
                int mid=(l+r)/2;
                if(p[mid]>=d[i]){
                    ans=mid;
                    r=mid-1;
                }else l=mid+1;
            }
            if(ans==m+1) continue;
            l=ans,r=m,ans1=ans-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(pd(i,mid)>(V*1.0)){
                    ans1=mid;
                    l=mid+1;
                }else r=mid-1;
            }
            if(ans1<ans) continue;
            b[++cnt]={ans,ans1};
        //    cout<<"i "<<i<<" "<<ans<<" "<<ans1<<endl;
        }
    }
    write(cnt);putchar(' ');
    sort(b+1,b+cnt+1);
    for(int i=1;i<=m;i++) st[i]=inf;
    for(int i=1;i<=cnt;i++){
        st[b[i].l]=min(st[b[i].l],b[i].r);
    }
    for(int i=1;i<=m;i++){
        modify(1,1,m,i,st[i]);
    }
    for(int i=1;i<=cnt;i++){
      //  cout<<"i "<<i<<" "<<b[i].l<<" "<<b[i].r<<endl;
        if(b[i].l==b[i-1].l&&b[i].r==b[i-1].r) continue;
        if(b[i].r<query(1,1,m,b[i].l+1,b[i].r)){
            c[++tot]={b[i].l,b[i].r};
        }
    }
    sort(c+1,c+tot+1);
    int mx=0,pr=0;
    for(int i=1;i<=tot;i++){
        if(c[i].l<=mx) continue;
        mx=c[i].r;
        pr++;
    }
    write(m-pr);puts("");
    return ;
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T=read();
    while(T--) work();
    return 0;
}