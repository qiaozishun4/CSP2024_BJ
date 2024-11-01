#include <bits/stdc++.h>
#define fin(str) freopen(str,"r",stdin)
#define fout(str) freopen(str,"w",stdout)
#define ll long long
using namespace std;

const int maxn=2e5+5;
const int maxL=1e6+5;
const double eps=1e-9;

int T;
int n,m,L,V,p[maxn];

struct car{
    int pos,v0,a;
    int flag,l,r;
}c[maxn];

int sum_p[maxL];


inline bool big(double x,double y) {return (x-y)>eps; }
inline bool check(int mid,int id){
    double v2=sqrt((p[mid]-c[id].pos)*2*c[id].a+c[id].v0*c[id].v0);
    return big(v2,V);
}

#define pii pair<int,int>
#define mkp(x,y) make_pair(x,y)
#define fir first
#define sec second
vector <pii> G[maxn];

int in[maxn],d[maxn];
queue <int> q;
inline int topo(){
    while (!q.empty()) q.pop();
    for (int i=0;i<=m;i++){
        d[i]=0;
        if (!in[i]) q.push(i);
    }
    while (!q.empty()){
        int x=q.front();
        q.pop();
        for (int i=0;i<G[x].size();i++){
            int v=G[x][i].fir,w=G[x][i].sec;
//            printf("%d-%d %d\n",x,v,d[x]);
            if (d[v]<d[x]+w) d[v]=d[x]+w;
            if (!--in[v]) q.push(v);
        }
    }
//    for (int i=1;i<=m;i++) printf("%d ",d[i]);
    return d[m];
}

inline void solve(){
    scanf("%d%d%d%d",&n,&m,&L,&V);
    for (int i=1;i<=n;i++) scanf("%d%d%d",&c[i].pos,&c[i].v0,&c[i].a);
    for (int i=0;i<=L;i++) sum_p[i]=0;
    for (int i=1;i<=m;i++) scanf("%d",&p[i]),sum_p[p[i]]++;
    for (int i=1;i<=L;i++) sum_p[i]+=sum_p[i-1];

    int tot=0;
    for (int i=1;i<=n;i++){
        c[i].flag=false;
        if (c[i].a==0){
            if (c[i].v0>V && sum_p[L]-sum_p[c[i].pos-1]>0){
                tot++;
                c[i].flag=true;
                c[i].l=lower_bound(p+1,p+m+1,c[i].pos)-p;
                c[i].r=m;
            }
        }else if (c[i].a>0){
            int fir=lower_bound(p+1,p+m+1,c[i].pos)-p;
            if (fir>m) continue;
            int l=fir,r=m;
            while (l<=r){
                int mid=(l+r)>>1;
                if (check(mid,i)) r=mid-1;
                else l=mid+1;
            }
            if (l>m) continue;
            tot++;
            c[i].flag=true;
            c[i].l=l;
            c[i].r=m;
        }else if (c[i].a<0){
            int fir=lower_bound(p+1,p+m+1,c[i].pos)-p;
            if (fir>m) continue;
            int l=fir,r=m;
            while (l<=r){
                int mid=(l+r)>>1;
                if (check(mid,i)) l=mid+1;
                else r=mid-1;
            }
            if (r<fir) continue;
            tot++;
            c[i].flag=true;
            c[i].l=fir;
            c[i].r=r;
        }
    }

    printf("%d ",tot);
//    for (int i=1;i<=n;i++) printf("%d : %d - %d\n",c[i].flag,c[i].l,c[i].r);

    for (int i=0;i<=m;i++) G[i].clear(),in[i]=0;
    for (int i=1;i<=n;i++){
        if (c[i].flag){
            G[c[i].l-1].push_back(mkp(c[i].r,1));
            in[c[i].r]++;
        }
    }
    for (int i=0;i<m;i++){
        G[i].push_back(mkp(i+1,0));
        in[i+1]++;
    }

    printf("%d\n",m-topo());
}

int main(){
    fin("detect.in");
    fout("detect.out");
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}
