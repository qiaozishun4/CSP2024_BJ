#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <vector>
// #include <ctime>
using namespace std;
long long read(){
    long long x=0,k=1;
    char c=getchar();
    for(;c!='-'&&(c<'0'||c>'9');c=getchar());
    if(c=='-') k=-1,c=getchar();
    for(;'0'<=c&&c<='9';x=(x<<1)+(x<<3)+c-'0',c=getchar());
    return x*k;
}
long long MAX=1e20;
long long n,a[200005],m;
// int ls(int x){return x<<1;}
// int rs(int x){return (x<<1)|1;}
// struct T{
//     int l,r;
//     long long mx,lzy;
//     void add(long long x){
//         mx+=x,lzy+=x;
//     }
// }t[4000106];
// void build(int rt,int l,int r){
//     t[rt].l=l,t[rt].r=r,t[rt].mx=-MAX,t[rt].lzy=0;
//     if(t[rt].l==t[rt].r) return;
//     int mid=l+r>>1;
//     build(ls(rt),l,mid);
//     build(rs(rt),mid+1,r);
// }
// void push_down(int rt){
//     if(!t[rt].lzy) return;
//     t[ls(rt)].add(t[rt].lzy),t[rs(rt)].add(t[rt].lzy);
//     t[rt].lzy=0;
// }
// void push_up(int rt){
//     t[rt].mx=max(t[ls(rt)].mx,t[rs(rt)].mx);
// }
// void add(int rt,int l,int r,long long x){
//     if(l<=t[rt].l&&t[rt].r<=r) {
//         t[rt].add(x);
//         return;
//     }
//     if(l>t[rt].r||t[rt].l>r) return;
//     push_down(rt);
//     int mid=t[rt].l+t[rt].r>>1;
//     if(l<=mid) add(ls(rt),l,r,x);
//     if(r>mid) add(rs(rt),l,r,x);
//     push_up(rt);
// }
// long long get_mx(int rt,int l,int r){
//     if(l<=t[rt].l&&t[rt].r<=r) return t[rt].mx;
//     if(l>t[rt].r||t[rt].l>r) return 0;
//     push_down(rt);
//     int mid=t[rt].l+t[rt].r>>1;
//     if(l>mid) return get_mx(rs(rt),l,r);
//     if(r<=mid) return get_mx(ls(rt),l,r);
//     return max(get_mx(ls(rt),l,r),get_mx(rs(rt),l,r));
// }
long long f[1000006],F,MX;
void build(int rt,int l,int r){
    for(int i=0;i<=m;i++) f[i]=-MAX;
    F=MX=0;
}
void add(int rt,int l,int r,long long x){
    if(l==r){
        f[l]+=x,MX=max(MX,f[l]+F);
        return;
    }
    if(l==0&&r==m){
        F+=x,MX+=x;
        return;
    }
}
long long get_mx(int rt,int l,int r){
    if(l==r){
        return f[l]+F;
    }
    if(l==0&&r==m){
        return MX;
    }
    return 0;
}
void solve(){
    cin>>n; m=0;
    for(int i=1;i<=n;i++) a[i]=read(),m=max(m,a[i]);
    // long long S=0;
    // for(int i=1;i<=n;i++) S+=a[i];
    // cout<<n<<" "<<m<<" "<<S<<" ";
    build(1,0,m); add(1,0,0,MAX);
    for(int i=2;i<=n;i++){
        long long mx=get_mx(1,0,m);
        mx=max(mx,get_mx(1,a[i],a[i])+a[i]);
        if(a[i]==a[i-1]){
            add(1,0,m,a[i]);
        }
        long long v0=get_mx(1,a[i-1],a[i-1]);
        if(mx>v0) add(1,a[i-1],a[i-1],mx-v0);
        // for(int j=0;j<=m;j++) cout<<get_mx(1,j,j)<<" ";
        // cout<<endl;
    }
    // S=0;
    // for(int i=1;i<=n;i++) S+=a[i];
    // cout<<n<<" "<<m<<" "<<S<<" ";
    cout<<get_mx(1,0,m)<<endl;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}