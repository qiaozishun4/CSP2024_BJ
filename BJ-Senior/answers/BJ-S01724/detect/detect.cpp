#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=1e6+5;
int T,n,m,tot,len,V;// diff of n & tot
int ans;
int p[N];
struct nd0{int d,v,a;} car[N];
struct nd{int l,r,p;} seg[N];
bool cmp(nd x,nd y){return x.p<y.p;}
int tr[M];
void init(){
    tot=ans=0;
    memset(tr,0,sizeof(tr));
    memset(p,0,sizeof(p));
}
void add(int i){
    i++;
    for(;i<=len+1;i+=i&-i) tr[i]++;
}
int ask(int i){
    i++;
    int res=0;
    for(;i;i-=i&-i) res+=tr[i];
    return res;
}
int read(){
    int x=0,f=1; char c=0;
    while(!isdigit(c)) {c=getchar(); if(c=='-') f=-1;}
    while(isdigit(c)) x=x*10+c-'0',c=getchar();
    return x*f;
}
void get_seg(int d,int v,int a,int &l,int &r){
    if(a==0){
        if(v>V) l=d,r=len;
        else l=d,r=d-1;
    }
    else if(a>0){
        int L=d,R=len+1;
        while(L<R){
            int mid = (L+R)>>1;
            double v1 = sqrt(double(v*v+2*a*(mid-d)));
            if(v1>V) R=mid;
            else L=mid+1;
        }
        l=L,r=len;
    }
    else{
        if(v<=V) {l=d,r=d-1; return;}
        int L=d-1,R=len;
        while(L<R){
            int mid = (L+R+1)>>1;
            int t = v*v+2*a*(mid-d);
            if(t<0) {R=mid-1; continue;}
            double v1 = sqrt(double(t));
            if(v1>V) L=mid;
            else R=mid-1;
        }
        l=d,r=L;
    }
}
void solve(){
    n=read(); m=read(); len=read(); V=read();
    for(int i=1;i<=n;i++)
        car[i].d=read(), car[i].v=read(), car[i].a=read();
    for(int i=1;i<=m;i++)
        p[i] = read();

    for(int i=1;i<=n;i++){
        int l,r;
        get_seg(car[i].d,car[i].v,car[i].a,l,r);
        if(l>r) continue;
        int x = upper_bound(p+1,p+m+1,r)-p-1;
        if(l<=p[x] && p[x]<=r) seg[++tot] = {l,r,p[x]};
    }
    sort(seg+1,seg+tot+1,cmp);
    for(int i=1;i<=tot;i++){
        if(ask(seg[i].r)-ask(seg[i].l-1)) continue;
        add(seg[i].p); ans++;
    }
    printf("%d %d\n",tot,m-ans);
}
int main(){
    // double x = clock();
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    T = read();
    while(T--){
        init();
        solve();
    }
    // printf("%.3lf\n",((double)clock()-x)/CLOCKS_PER_SEC);
    return 0;
}