#include <bits/stdc++.h>
#define fin(str) freopen(str,"r",stdin)
#define fout(str) freopen(str,"w",stdout)
#define ll long long
using namespace std;

const int maxn=2e5+5;
const int maxlog=21;

int T,n,m,K,a_pre[maxn],a[maxn],q[maxn],X[5];

char ch[maxn];
int d[maxlog][maxn];

inline int lowbit(int x) {return x&-x; }
inline int log2_up(int x){
    int p=-1,x0=x;
    while (x){
        p++;
        x>>=1;
    }
    if ((1<<p)==lowbit(x0)) return p;
    else return p+1;
}


#define pii pair<int,int>
#define fir first
#define sec second
#define mkp(x,y) make_pair(x,y)
ll ans[maxn];
struct node{
    set <pii> win;
    ll may_win;
    inline node() {win.clear(),may_win=0; }
    inline void clear(){
        win.clear();
        may_win=0;
    }
    inline void print(){
        printf("win : \n");
        for (set<pii>::iterator it=win.begin();it!=win.end();it++){
            printf("%d\n",it->sec);
        }
        printf("may_win : %lld\n",may_win);
    }
    inline ll calc(){
        ll res=may_win;
        for (set<pii>::iterator it=win.begin();it!=win.end();it++){
            res+=(it->sec);
        }
        return res;
    }
}c[maxlog][maxn];
inline node comb(node x,node y,int D,int layer){
    if (D) swap(x,y);
    node res;
    while (x.win.size()){
        pii now=*x.win.begin();
        if (now.fir<layer) x.win.erase(now);
        else break;
    }

    if (x.win.size()){
        if (x.may_win){
            for (set<pii>::iterator it=y.win.begin();it!=y.win.end();it++) x.win.insert(*it);
            res.win=x.win;
            res.may_win=x.may_win+y.may_win;
        }else{
            res.win=x.win;
            res.may_win=x.may_win;
        }
    }else{
        if (x.may_win){
            for (set<pii>::iterator it=y.win.begin();it!=y.win.end();it++) x.win.insert(*it);
            res.win=x.win;
            res.may_win=x.may_win+y.may_win;
        }else{
            res.win=y.win;
            res.may_win=y.may_win;
        }
    }

    return res;
}
int lft[maxlog][maxn];
inline void solve2(){
    for (int i=1;i<=n;i++) lft[0][i]=i;
    for (int i=1;i<=K;i++){
        for (int j=1;j<=(1<<(K-i));j++){
            int x=lft[i-1][j*2-1],y=lft[i-1][j*2];
            if (d[i][j]) swap(x,y);
            if (a[x]>=i) lft[i][j]=x;
            else lft[i][j]=y;
        }
    }
    ll res=0;
    for (int i=1;i<=m;i++) res^=(1ll*lft[log2_up(q[i])][1]*i);
    printf("%lld\n",res);
}

inline void solve(){
    int flag=true;
    for (int i=1;i<=m;i++) if (lowbit(q[i])!=q[i]) flag=false;
    if (flag){
        solve2();
        return ;
    }
    for (int i=1;i<=n;i++) ans[i]=0;
    int k=0;
    for (int i=1;i<=(1<<K);i++){
        c[0][i].clear();
        c[0][i].may_win=i;
    }
    for (int i=1;i<=K;i++) for (int j=1;j<=(1<<(K-i));j++) c[i][j]=comb(c[i-1][j*2-1],c[i-1][j*2],d[i][j],i);
    for (int i=1;i<=n;i++){
        if (log2_up(i)!=k) k=log2_up(i);
        c[0][i].clear();
        c[0][i].win.insert(mkp(a[i],i));
        int p=1,x=i;
        while (p<=k){
            int f=(x+1)/2;
            if (f*2==x) c[p][f]=comb(c[p-1][f*2-1],c[p-1][x],d[p][f],p);
            else c[p][f]=comb(c[p-1][x],c[p-1][f*2],d[p][f],p);
            x=f;
            p++;
        }
        //c[k][1].print();
        ans[i]=c[k][1].calc();
        //printf("%d : %lld\n",i,ans[i]);
        //if (i==5){
          //  printf("-------------\n");
         //   c[1][4].print();
        //    printf("--------------\n");
//
       // }
    }
    ll res=0;
    for (int i=1;i<=m;i++) res^=ans[q[i]]*i;
    printf("%lld\n",res);
}

int main(){
    fin("arena.in");
    fout("arena.out");

    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a_pre[i]);
    for (int i=1;i<=m;i++) scanf("%d",&q[i]);
    K=log2_up(n);
    for (int i=1;i<=K;i++){
        scanf("%s",ch+1);
        for (int j=1;j<=(1<<(K-i));j++){
            d[i][j]=ch[j]-'0';
        }
    }
    scanf("%d",&T);
    while (T--){
        scanf("%d%d%d%d",&X[0],&X[1],&X[2],&X[3]);
        for (int i=1;i<=n;i++) a[i]=(a_pre[i]^X[i%4]);
        solve();
    }
    return 0;
}
