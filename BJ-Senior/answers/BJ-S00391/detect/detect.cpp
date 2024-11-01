#include<bits/stdc++.h>
#define rep(i,S,T) for(int i=S;i<=T;++i)
#define per(i,T,S) for(int i=T;i>=S;--i)
using namespace std;
template<typename T>
inline void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}
const int N=1e6+10,INF=0x3f3f3f3f;
int T,n,m,L,V,sum[N],p[N],ans1;
struct CAR{
    int d,v,a;
    int l,r;
}c[N];
void get(CAR &x){
    if(x.v>V&&x.a>=0) x.l=x.d,x.r=L;
    else if(x.v>V){
            /*
        int l=x.d,r=L;
        while(l<=r){
            int mid=(l+r)>>1;
            int S=mid-x.d;
            if(x.v*x.v+2*x.a*S>V*V) l=mid+1;
            else r=mid-1;
        }
        */
        int s=(V*V-x.v*x.v)/(2*x.a);
        if((-V*V+x.v*x.v)%(-2*x.a)==0) s--;
        x.l=x.d,x.r=min(L,x.d+s);
    }
    else if(x.v<=V&&x.a<=0) x.l=-1,x.r=-1;
    else if(x.v<=V){
        int s=(V*V-x.v*x.v)/(2*x.a)+1;
        if(x.d+s>L) x.l=-1,x.r=-1;
        else x.l=min(L,x.d+s),x.r=L;
    }
}
int tagL[N],tagR[N],f[N][2],have[N];
struct SGT{
    #define ls p*2
    #define rs p*2+1
    struct node{
        int l,r,f;
    }t[N*4];
    void clr(){memset(t,0,sizeof(t));}
    void pushup(int p){t[p].f=min(t[ls].f,t[rs].f);}
    void build(int p,int l,int r){
        t[p].l=l;t[p].r=r;t[p].f=INF;
        if(l==r) return;
        int mid=(l+r)>>1;
        build(ls,l,mid);
        build(rs,mid+1,r);
    }
    void upd(int p,int x,int k){
        if(t[p].l==t[p].r){t[p].f=k;return;}
        if(x<=t[ls].r) upd(ls,x,k);
        else upd(rs,x,k);
        pushup(p);
    }
    int query(int p,int nl,int nr){
        if(nl>nr) return INF;
        int res=INF;
        if(nl<=t[p].l&&t[p].r<=nr) return t[p].f;
        if(nl<=t[ls].r) res=min(res,query(ls,nl,nr));
        if(nr>=t[rs].l) res=min(res,query(rs,nl,nr));
        return res;
    }
}t;
void solve(){
    read(n);read(m);read(L);read(V);ans1=0;
    t.clr();
    t.build(1,1,L);
    rep(i,1,n){
        read(c[i].d);read(c[i].v);read(c[i].a);
        get(c[i]);
        //cout<<c[i].l<<" "<<c[i].r<<endl;
    }

    rep(i,0,L) sum[i]=0,f[i][1]=INF,f[i][0]=INF,tagR[i]=tagL[i]=0,have[i]=0;
    rep(i,1,m){read(p[i]);sum[p[i]]++;have[p[i]]=1;}
    rep(i,1,L) sum[i]+=sum[i-1];
    rep(i,1,n){
        if(c[i].l==-1) continue;
        if(sum[c[i].r]-sum[c[i].l-1]>0){
            ans1++;
            if(c[i].l!=-1) tagL[c[i].l]=1,tagR[c[i].r]=max(tagR[c[i].r],c[i].l);
        }
    }
    rep(i,0,L) tagR[i]=max(tagR[i],tagR[i-1]);
    int now=0;
    rep(i,1,L){
        if(tagL[i]) now=i;
        //rep(j,now,i-1) f[i][0]=min(f[i][0],f[j][1]);
        if(have[i]){
            if(tagR[i-1]==0) f[i][1]=1;
            else f[i][1]=t.query(1,tagR[i-1],i-1)+1;

            t.upd(1,i,f[i][1]);
            //rep(j,tagR[i-1],i-1) f[i][1]=min(f[i][1],f[j][1]+1);
        }
        //cout<<f[i][0]<<" "<<f[i][1]<<endl;
    }
    //(i,1,L) cout<<f[i][0]<<" "<<f[i][1]<<endl;
    int ans2=m+1;
    rep(i,now,L) ans2=min(ans2,f[i][1]);
    if(now==0) ans2=0;
    ans2=min(ans2,f[L][1]);
    printf("%d %d\n",ans1,m-ans2);
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    read(T);
    while(T--) solve();
    return 0;
}
