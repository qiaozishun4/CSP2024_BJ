#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAXN 100005
int T,n,m,L,V,d[MAXN],v[MAXN],a[MAXN],b[MAXN],sum[1000005],cnt;
struct node{
    int l,r;
}car[MAXN];
void init(){
    memset(sum,0,sizeof(sum));
    cnt=0;
}
node getspd(int id){
    if(a[id]==0){
        if(v[id]>V) return {d[id],L};
        else return {-1,-1};
    }
    else if(a[id]>0){
        int pos=d[id];
        if(v[id]<=V){
            pos=d[id]+1.*(V*V-v[id]*v[id])/(2*a[id]);
            while(pos<=L&&1.*(pos-d[id])*2*a[id]+1.*v[id]*v[id]<=V*V) pos++;
        }
        return {pos,L};
    }
    else{
        if(v[id]<=V) return {-1,-1};
        int pos=d[id]+1.*(V*V-v[id]*v[id])/(2*a[id])+1;
        while(pos>d[id]&&1.*(pos-d[id])*2*a[id]+1.*v[id]*v[id]<=V*V) pos--;
        return {d[id],min(L,pos)};
    }
}
bool cmp(node x,node y){
    return x.r>y.r||x.r==y.r&&x.l<y.l;
}
bool cmp2(int x,int y){
    return x>y;
}
inline int getsum(int l,int r){
    if(l==0) return sum[r];
    else return sum[r]-sum[l-1];
}
inline int read(){
    int w=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        w=w*10+ch-'0';
        ch=getchar();
    }
    return w*f;
}
void solve(){
    init();
    n=read(),m=read(),L=read(),V=read();
    for(int i=1;i<=n;i++) d[i]=read(),v[i]=read(),a[i]=read();
    for(int i=1;i<=m;i++){
        b[i]=read();
        sum[b[i]]++;
    }
    for(int i=1;i<=L;i++) sum[i]+=sum[i-1];
    for(int i=1;i<=n;i++){
        node now=getspd(i);
        if(now.l<0||now.l>L) continue;
        if(getsum(now.l,now.r)>0){
            car[++cnt]=now;
        }
    }
    sort(b+1,b+1+m,cmp2);
    sort(car+1,car+1+cnt,cmp);
    int need=0,idx=cnt;
    while(idx>0){
        int l=car[idx].l,r=car[idx].r;
        do{
            idx--;
            l=max(l,car[idx].l);
            r=min(r,car[idx].r);
        }while(idx&&l<=r&&getsum(l,r)>0);
        need++;
    }
    printf("%d %d\n",cnt,m-need);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    T=read();
    while(T--) solve();
    return 0;
}