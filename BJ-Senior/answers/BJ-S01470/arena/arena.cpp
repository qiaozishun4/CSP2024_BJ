#include<bits/stdc++.h>
#define up(i,l,r) for(int i=(l);i<=(r);++i)
#define down(i,l,r) for(int i=(l);i>=(r);--i)
#define pi pair<int,int>
#define p1 first
#define p2 second
#define m_p make_pair
#define p_b push_back
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
inline ll read(){
    ll x=0;short t=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*t;
}
int n,m,a[maxn],k,t;
string s[18];
struct nd {
    ll sm[18];
    ll sm2[18];
    nd(){memset(sm,0,sizeof(sm)),memset(sm2,0,sizeof(sm2));}
    void clear(){memset(sm,0,sizeof(sm)),memset(sm2,0,sizeof(sm2));}
    void init(int id,int x){
        up(i,0,17)sm[i]=sm2[i]=0;
        if(x==-1)sm2[0]=id;
        else sm[min(x,17)]=id;
    }
};
inline void cal(nd &a,nd &b,nd &res,int lim){
    res.clear();
    bool ok=0;ll sm=0;
    up(i,0,17)if(a.sm[i]||a.sm2[i]){
        if(i<lim)ok=1,sm+=a.sm2[i];
        else res.sm[i]+=a.sm[i],res.sm2[i]+=a.sm2[i];
    }res.sm2[lim]+=sm;
    if(ok){
        up(i,0,17)res.sm[i]+=b.sm[i],res.sm2[i]+=b.sm2[i];
    }
}
inline void calc(nd &a,nd &b,nd &res,int d,int g){
    if(s[d][g]=='0')cal(a,b,res,d);else cal(b,a,res,d);
}
int f[maxn<<1];
struct SegTree {
    nd T[1<<19];
    #define ls(p) (p<<1)
    #define rs(p) (p<<1|1)
    void bd(int l,int r,int p,int dep){
        if(l==r){
            T[p].init(l,-1);return;
        }int mid=l+r>>1;
        bd(l,mid,ls(p),dep-1),bd(mid+1,r,rs(p),dep-1);
        int bel=((l-1)>>dep)+1;
        calc(T[ls(p)],T[rs(p)],T[p],dep,bel);
    }void modify(int l,int s,int t,int p,int dep){
        if(s==t){
            T[p].init(l,a[l]);return;
        }int mid=s+t>>1;
        if(l<=mid)modify(l,s,mid,ls(p),dep-1);else modify(l,mid+1,t,rs(p),dep-1);
        int bel=((l-1)>>dep)+1;
        calc(T[ls(p)],T[rs(p)],T[p],dep,bel);
    }ll qry(int s,int t,int p,int k){
        if(t-s+1<=k){
            ll res=0;
            up(i,0,17)res+=T[p].sm[i]+T[p].sm2[i];
            return res;
        }int mid=s+t>>1;
        return qry(s,mid,ls(p),k);
    }
}T;
vector<int>G[maxn];
ll res[maxn];
void qry(){
    T.bd(1,(1<<k),1,k);
    up(i,1,n){
        T.modify(i,1,(1<<k),1,k);
        if(G[i].empty())continue;
        ll ans=T.qry(1,(1<<k),1,f[i]);
        //printf("ans:%lld\n",ans);
        for(int x:G[i])res[x]=ans;
    }
    ll all=0;
    up(i,1,m)all^=(i*1ll*res[i]);
    printf("%lld\n",all);
}
int tmp[maxn],S[4];
void slv(){
    n=read(),m=read();
    for(int x=1;x<=2*n;x<<=1)f[x]=x;
    down(i,2*n,1)if(!f[i])f[i]=f[i+1];
    up(i,1,n)tmp[i]=read();
    up(i,1,m){
        int c=read();G[c].p_b(i);
    }
    while((1<<k)<n)k++;
    up(i,1,k)cin>>s[i],s[i]=" "+s[i];
    t=read();
    while(t--){
        up(i,0,3)S[i]=read();
        up(i,1,n)a[i]=tmp[i]^S[i%4];
        qry();
    }
}int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    slv();
    fclose(stdin);
    fclose(stdout);
    //cerr<<clock()*1.0/CLOCKS_PER_SEC<<"s\n";
    return 0;
}