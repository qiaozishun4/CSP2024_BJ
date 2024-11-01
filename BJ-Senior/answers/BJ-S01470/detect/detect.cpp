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
}int n,m,L,V;
struct nd {
    int d,v,a;
}d[maxn];
int P[maxn];
bool chk(int pos,int i){
    ll f=d[i].v*1ll*d[i].v+2ll*d[i].a*(P[pos]-d[i].d);
    return (f>V*1ll*V);
}
bool cmp(pi a,pi b){
    return a.p2<b.p2;
}
void slv(){
    n=read(),m=read(),L=read(),V=read();
    up(i,1,n)d[i].d=read(),d[i].v=read(),d[i].a=read();
    up(i,1,m)P[i]=read();sort(P+1,P+m+1);
    vector<pi>OK;
    up(i,1,n){
        if(d[i].a>0){
            int p=lower_bound(P+1,P+m+1,d[i].d)-P;
            if(p>m)continue;
            if(!chk(m,i))continue;
            int l=p-1,r=m;
            while(l+1<r){
                int mid=l+r>>1;
                if(chk(mid,i))r=mid;
                else l=mid;
            }OK.p_b(m_p(r,m));
        }else {
            int p=lower_bound(P+1,P+m+1,d[i].d)-P;
            if(p>m)continue;
            if(!chk(p,i))continue;
            int l=p,r=m+1;
            while(l+1<r){
                int mid=l+r>>1;
                if(chk(mid,i))l=mid;
                else r=mid;
            }OK.p_b(m_p(p,l));
        }
    }sort(OK.begin(),OK.end(),cmp);
    set<int>s;
    for(auto it:OK){
        auto p=s.lower_bound(it.p1);
        if(p==s.end())s.insert(it.p2);
        else if((*p)>it.p2)s.insert(it.p2);
    }printf("%d %d\n",(int)OK.size(),m-(int)s.size());
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t=read();while(t--)slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}