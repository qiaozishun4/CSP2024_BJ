#include<bits/stdc++.h>
#define LL long long
#define CLR(a,x) memset(a,x,sizeof(a))
using namespace std;
const int N=1e5+5;
const int M=1e6+5;
const int I_INF=2e9+5;
template<typename T>
inline void read(T &x) {
    int f=1;x=0;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
int n,m,L,V,d[N],a[N],v[N],p[N],ans,t,ans2;
bool vis[N];
int line[N];
struct BIT {
    int bit[N];
    int lowbit(int x){return x&-x;}
    void update(int x,int d){for(;x<=m;x+=lowbit(x))bit[x]+=d;}
    int query(int x){int res=0;for(;x;x-=lowbit(x))res+=bit[x];return res;}
    int query(int l,int r){return query(r)-query(l-1);}
}bit;
struct Seg {
    int l,r;
    bool operator < (const Seg &rhs) const {
        if(l==rhs.l)return r>rhs.r;
        return l<rhs.l;
    }
}seg[N];
void add_ans(int l,int r) {
    if(l>r)return;
    seg[++ans]={l,r};
}

void solve() {
    ans=ans2=0;
    read(n),read(m),read(L),read(V);
    for(int i=0;i<=m;i++)vis[i]=line[i]=0,bit.bit[i]=0;
    for(int i=1;i<=n;i++)
        read(d[i]),read(v[i]),read(a[i]);
    for(int i=1;i<=m;i++)
        read(p[i]);
    for(int i=1;i<=n;i++) {
        if(a[i]==0) {
            if(v[i]<=V)continue;
            int pos=lower_bound(p+1,p+m+1,d[i])-p;
            add_ans(pos,m);
        } else if(a[i]>0) {
            if(v[i]>V) {
                int pos=lower_bound(p+1,p+m+1,d[i])-p;
                add_ans(pos,m);
                continue;
            }
            int val=V*V-v[i]*v[i],s;
            s=val/(2*a[i])+1+d[i];
            if(s>p[m])continue;
            int pos=lower_bound(p+1,p+m+1,s)-p;
            add_ans(pos,m);
        } else {
            if(v[i]<=V)continue;
            int val=V*V-v[i]*v[i],s;
            if(val%(2*a[i])==0)s=val/(2*a[i])-1;
            else s=val/(2*a[i]);
            s+=d[i];
            int pos1=lower_bound(p+1,p+m+1,d[i])-p;
            int pos2=upper_bound(p+1,p+m+1,s)-p-1;
            add_ans(pos1,pos2);
        }
    }
    sort(seg+1,seg+ans+1);
    for(int i=1;i<=ans;i++)bit.update(seg[i].r,1);
    for(int i=1;i<=ans;i++) {
        bit.update(seg[i].r,-1);
        if(bit.query(seg[i].l,seg[i].r)==0)
            line[seg[i].l]=max(line[seg[i].l],seg[i].r);
    }
    for(int i=1;i<=m;i++) {
        if(!line[i])continue;
        ans2++;
        i=line[i];
    }
    printf("%d %d\n",ans,m-ans2);
}
int main() {
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    read(t);
    while(t--)
        solve();
    return 0;
}
//15:49
