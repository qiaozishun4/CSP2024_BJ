#include<bits/stdc++.h>
using namespace std;
template<class T>
void read(T&x){
    x=0;T f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=((x<<3)+(x<<1)+(ch&15));
    x=x*f;
}
template<class T,class...Args>
void read(T&x,Args&...args){read(x);read(args...);}
#define FileIO(csp) freopen(csp".in","r",stdin),freopen(csp".out","w",stdout)
#define For(i,x,y) for(int i=(x);(i)<=(y);++i)
#define Rof(i,x,y) for(int i=(x);(i)>=(y);--i)
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define chkmax(x,y) x=max((x),(y))
#define chkmin(x,y) x=min((x),(y))
const int N=1e5+5;
int n,m,L,mps;
long double d[N],v[N],a[N],l1[N],r1[N],p1[N],mp[N*5],V;
int l[N],r[N],p[N],nx[N];
pair<int,int>ls[N],rs[N];
bool in[N],ok[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        mps=0;
        memset(in,0,sizeof(in));
        memset(ok,0,sizeof(ok));
        memset(mp,0,sizeof(mp));
        int VV;
        cin>>n>>m>>L>>VV;
        V=VV;
        V+=0.0001;
        For(i,1,n){
            int dd,vv,aa;
            cin>>dd>>vv>>aa;
            d[i]=dd;v[i]=vv;a[i]=aa;
            if(a[i]>0){
                if(v[i]>V)l1[i]=d[i],r1[i]=L;
               else l1[i]=min(L,d[i]+(V*V-v[i]*v[i])/2/a[i]),r1[i]=L;
            }else if(a[i]==0){
                if(v[i]>V)l1[i]=d[i],r1[i]=L;
                else l1[i]=L+1,r1[i]=L+1;
            }else{
                if(v[i]<V)l1[i]=L+1,r1[i]=L+1;
                else l1[i]=d[i],r1[i]=min(L,d[i]+(v[i]*v[i]-V*V)/2/-a[i]);
            }
        }
    For(i,1,m){
        int pp;
        cin>>pp;
        p1[i]=pp;
    }
    For(i,1,n){mp[++mps]=l1[i];mp[++mps]=r1[i];}
    For(i,1,m)mp[++mps]=p1[i];
    mp[++mps]=L;
    sort(mp+1,mp+mps+1);
    mps=unique(mp+1,mp+mps+1)-mp;
    For(i,1,n)
        l[i]=lower_bound(mp+1,mp+mps+1,l1[i])-mp,
        r[i]=lower_bound(mp+1,mp+mps+1,r1[i])-mp;
    For(i,1,m)p[i]=lower_bound(mp+1,mp+mps+1,p1[i])-mp;
    L=lower_bound(mp+1,mp+mps+1,L)-mp;
    For(i,1,n)ls[i]=make_pair(l[i],i);
    For(i,1,n)rs[i]=make_pair(r[i],i);
    sort(ls+1,ls+n+1);
    sort(rs+1,rs+n+1);
    sort(p+1,p+m+1);
    int lp=0,rp=0,cr=1,lcr=0,ans1=0,ans2=0;
    For(i,1,m){
        while(lp<n&&ls[lp+1].first<=p[i]){
            int nl=ls[lp+1].first,x=ls[lp+1].second;
            in[x]=1;
            if(r[x]>=p[i])ok[x]=1;
            lp++;
        }
        while(rp<n&&rs[rp+1].first<p[i]){
            int nr=rs[rp+1].first,x=rs[rp+1].second;
            in[x]=0;
            rp++;
        }
    }
    while(rp<n&&rs[rp+1].first<=L){
        int nr=rs[rp+1].first,x=rs[rp+1].second;
        in[x]=0;
        rp++;
    }
    lp=rp=0;
    For(i,1,m){
        while(lp<n&&ls[lp+1].first<=p[i]){
            int nl=ls[lp+1].first,x=ls[lp+1].second;
            in[x]=1;
            lp++;
        }
        while(rp<n&&rs[rp+1].first<p[i]){
            int nr=rs[rp+1].first,x=rs[rp+1].second;
            in[x]=0;
            if(ok[x])nx[x]=lcr;
            rp++;
        }
        while(cr<=n&&(!ok[rs[cr].second]||in[rs[cr].second]))cr++;
        lcr=cr;
    }
    while(rp<n&&rs[rp+1].first<=L){
        int nr=rs[rp+1].first,x=rs[rp+1].second;
        in[x]=0;
        if(ok[x])nx[x]=lcr;
        rp++;
    }
    For(i,1,n)if(ok[i])ans1++;
    cr=1;
    while(cr<=rp){
        cr=nx[rs[cr].second];
        ans2++;
    }
    cout<<ans1<<" "<<m-ans2<<endl;
    }
    return 0;
}