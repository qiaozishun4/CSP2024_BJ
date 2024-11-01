#include<bits/stdc++.h>
using namespace std;
#define int long long
#define min(x,y) ((x)<(y)?(x):(y))
int n,m,l,V;
int d[100005],v[100005],a[100005],p[100005];
struct frac{
    int x,y;//x分之y
};
bool operator<(frac x,frac y){
    return x.y*y.x<y.y*x.x;
}bool operator==(frac x,frac y){
    return x.y*y.x==y.y*x.x;
}bool operator<=(frac x,frac y){
    return (x<y||x==y);
}
int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}
frac operator+(frac x,frac y){
    frac res={x.x*y.x,x.y*y.x+x.x*y.y};
    int g=gcd(res.x,res.y);
    return {res.x/g,res.y/g};
}
int bp[100005],ep[100005];
int tot;
void calc(int x){
    if(d[x]>p[m])return;
    if(a[x]==0){
        if(v[x]<=V)return;
        int l=1,r=m,mid;
        while(l<r){
            mid=l+r>>1;
            if(p[mid]>=d[x])r=mid;
            else l=mid+1;
        }
        bp[++tot]=l;
        ep[tot]=m;
        return;
    }
    if(a[x]<0){
        if(v[x]<=V)return;
        frac end=frac{1,d[x]}+frac{-a[x]-a[x],v[x]*v[x]-V*V};
        // cout<<"!"<<end.x<<" "<<end.y<<endl;
        int bp1,ep1;
        int l=1,r=m,mid;
        while(l<r){
            mid=l+r>>1;
            if(p[mid]>=d[x])r=mid;
            else l=mid+1;
        }
        bp1=l;
        l=1,r=m,mid;
        while(l<r){
            mid=l+r+1>>1;
            if(frac{1,p[mid]}<end)l=mid;
            else r=mid-1;
        }
        ep1=l;
        if(ep1<bp1)return;
        ep[++tot]=ep1;
        bp[tot]=bp1;
        return;
    }
    if(v[x]>V){
        // cout<<d[x]<<" "<<p[m]<<endl;
        int l=1,r=m,mid;
        while(l<r){
            mid=l+r>>1;
            if(p[mid]>=d[x])r=mid;
            else l=mid+1;
        }
        bp[++tot]=l;
        ep[tot]=m;
        return;
    }
    frac beg=frac{1,d[x]}+frac{a[x]+a[x],-v[x]*v[x]+V*V};
    // cout<<"!"<<beg.x<<" "<<beg.y<<endl;
    if(frac{1,p[m]}<=beg)return;
    int l=1,r=m,mid;
    while(l<r){
        mid=l+r>>1;
        if(beg<frac{1,p[mid]})r=mid;
        else l=mid+1;
    }
    ep[++tot]=m;
    bp[tot]=l;
}
vector<int>ve[100005];
int t[400005],lz[400005];
#define ls (p<<1)
#define rs (p<<1|1)
#define mid (l+r>>1)
void pu(int p){
    t[p]=min(t[ls],t[rs]);
    // cout<<"?"<<p<<" "<<t[p]<<" "<<t[ls]<<" "<<t[rs]<<endl;;
}
void bd(int l,int r,int p){
    lz[p]=2e18;
        // cout<<l<<" "<<r<<" "<<p<<endl;
    if(l==r){
        t[p]=(l==0?0:2e9);
        return;
    }
    bd(l,mid,ls);
    bd(mid+1,r,rs);
    pu(p);
}
void pd(int p){
    if(lz[p]==2e18)return;
    lz[ls]=lz[rs]=t[ls]=t[rs]=lz[p];
    lz[p]=2e18;
}
void upd(int l,int r,int ml,int mr,int x,int p){
    if(ml<=l&&r<=mr){
        t[p]=x;
        lz[p]=x;
        return;
    }
    pd(p);
    if(mid>=ml)upd(l,mid,ml,mr,x,ls);
    if(mid+1<=mr)upd(mid+1,r,ml,mr,x,rs);
    pu(p);
    return;
}
int qu(int l,int r,int ml,int mr,int p){
    // cout<<l<<" "<<r<<" "<<p<<endl;
    if(ml<=l&&r<=mr)return t[p];
    pd(p);
    int res=2e18;
    
    if(mid>=ml){
        int x=qu(l,mid,ml,mr,ls);
        res=min(res,x);
    }
    if(mid+1<=mr){
        int x=qu(mid+1,r,ml,mr,rs);
        res=min(res,x);
    }
    return res;
}
void prt(int l,int r,int p){
        // cout<<l<<" "<<r<<" "<<t[p]<<endl;
    if(l==r){
        cout<<t[p]<<" ";
        return;
    }
    pd(p);
    prt(l,mid,ls),prt(mid+1,r,rs);
}
#undef ls
#undef rs
#undef mid
void read(int &x){
    x=0;
    char c=getchar();
    bool f=0;
    while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    if(f)x=-x;
}
void slv(){
    read(n),read(m),read(l),read(V);
    for(int i=1;i<=n;i++){
        read(d[i]),read(v[i]),read(a[i]);
    }
    for(int i=1;i<=m;i++)read(p[i]);
    for(int i=1;i<=n;i++){
        calc(i);
    }
    cout<<tot<<" ";
    for(int i=1;i<=tot;i++)ve[ep[i]].push_back(bp[i]);
    bd(0,m,1);
    for(int i=1;i<=m;i++){
        // cout<<"!!!"<<i<<" ";
        int mn=qu(0,m,0,i-1,1);
        for(int x:ve[i]){
            // cout<<x<<" ";
            if(x>0)
            upd(0,m,0,x-1,2e9,1);
        }
        // cout<<mn;
        // cout<<endl;
        upd(0,m,i,i,mn+1,1);
        // prt(0,m,1);
        // cout<<endl;
    }
    int mn=qu(0,m,0,m,1);
    cout<<m-mn<<endl;
    for(int i=1;i<=tot;i++)bp[i]=ep[i]=0;
    tot=0;
    for(int i=1;i<=m;i++)ve[i].clear();
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    read(T);
    while(T--)
    slv();
    fclose(stdin);
    fclose(stdout);
    // cerr<<clock()*1.0/CLOCKS_PER_SEC<<"s\n";
    return 0;
}