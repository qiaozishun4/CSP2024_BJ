#include <iostream>
using namespace std;
typedef long long ll;
const int N=100005, M=100005;
int n, m, ap[N], c[M], k, T, x[4], a[N], ans[N], tree[4*N], nb[4*N];
string d[25];
int sk(int x){
    int res=0;
    if((x&(x-1))==0) res--;
    while(x) x>>=1, res++;
    return res;
}
void build(int p, int pl, int pr, int l, int r){
    if(pl==pr){
        tree[p]=a[pl], nb[p]=p;
        return;
    }
    int mid=pl+pr>>1;
    build(p<<1,pl,mid,l,r);
    build(p<<1|1,mid+1,pr,l,r);
    char t=d[k-sk(pr-pl+1)+1][pr/(pr-pl+1)];
    if(t=='0'){
        if(tree[p<<1]>=k-sk(pr-pl+1)+1) tree[p]=tree[p<<1], nb[p]=nb[p<<1];
        else tree[p]=tree[p<<1|1], nb[p]=nb[p<<1|1];
    }
    if(t=='1'){
        if(tree[p<<1|1]<k-sk(pr-pl+1)+1) tree[p]=tree[p<<1], nb[p]=nb[p<<1];
        else tree[p]=tree[p<<1|1], nb[p]=nb[p<<1|1];
    }
}
int query(int p, int pl, int pr, int l, int r){
    if(pl==l&&pr==r) return nb[p];
    if(pl>r||pr<l) return 0;
    int mid=pl+pr>>1;
    return query(p<<1,pl,mid,l,r)+query(p<<1|1,mid+1,pr,l,r);
}
int main(){
    freopen("arena2.in","r",stdin);
    freopen("arena2.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&ap[i]);
    for(int i=1;i<=m;i++) scanf("%d",&c[i]);
    k=sk(n);
    for(int i=1;i<=k;i++) cin>>d[i];
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&x[0],&x[1],&x[2],&x[3]);
        for(int i=1;i<=n;i++) a[i]=ap[i]^x[i%4];
        build(1,1,1<<k,1,1<<k);
        int tot=0;
        for(int i=1;i<=m;i++) tot^=i*query(1,1,1<<k,1,c[i]);
        printf("%d\n",tot);
    }
    return 0;
}