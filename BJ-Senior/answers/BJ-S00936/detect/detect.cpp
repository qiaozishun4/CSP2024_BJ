#include<bits/stdc++.h>
using namespace std;
#define int long long
#define LD long double
#define pii pair<int,int>
#define fr first
#define sc second
#define mk make_pair
#define pb push_back
int read(){int x=0,f=1;char c=getchar();while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();};while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();return x*f;}
const int MAXN=100010;
int n,m,L,V,p[MAXN];
struct node{
    int d,v,x;
}a[MAXN];
bool check(int d,int v,int x){
    if(x>0){
        if(d>p[m])return 0;
        int s=p[m]-d;
        return v*v+2*x*s>V*V;
    }
    if(x==0){
        if(d>p[m])return 0;
        return v>V;
    }
    if(x<0){
        int t=v*v/(2*-x);
        int l=1,r=m;
        while(l<r){
            int mid=(l+r)>>1;
            if(p[mid]>=d)r=mid;
            else l=mid+1;
        }
        if(p[l]<d||p[l]>d+t)return 0;
        int s=p[l]-d;
        return v*v+2*x*s>V*V;
    }
}
pii pr[MAXN];
int cnt;
void inst(int d,int v,int x){
    int L=1,R=m;
    if(x>0){
        int s=max(0ll,(V*V-v*v)/(2*x)+1);
        int l=1,r=m;
        while(l<r){
            int mid=(l+r)>>1;
            if(p[mid]>=d+s)r=mid;
            else l=mid+1;
        }
        L=l,R=m;
    }
    if(x==0){
        int l=1,r=m;
        while(l<r){
            int mid=(l+r)>>1;
            if(p[mid]>=d)r=mid;
            else l=mid+1;
        }
        L=l,R=m;
    }
    if(x<0){
        int s=max(0ll,(V*V-v*v+1)/(2*x));
        int l=1,r=m;
        while(l<r){
            int mid=(l+r)>>1;
            if(p[mid]>=d)r=mid;
            else l=mid+1;
        }
        L=l;
        l=1,r=m;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(p[mid]<=d+s)l=mid;
            else r=mid-1;
        }
        R=l;
        if(V==v)L=R=l;
    }
    pr[++cnt]=mk(L,R);
}
bool cmp(pii x,pii y){return x.sc<y.sc;}
void slv(){cnt=0;
    n=read(),m=read(),L=read(),V=read();
    for(int i=1;i<=n;i++){
        a[i].d=read(),a[i].v=read(),a[i].x=read();
    }
    for(int i=1;i<=m;i++)p[i]=read();
    sort(p+1,p+m+1);
    for(int i=1;i<=n;i++){
        if(check(a[i].d,a[i].v,a[i].x)){
            inst(a[i].d,a[i].v,a[i].x);
        }
    }
    sort(pr+1,pr+cnt+1,cmp);
    int lst=0,ans=0;
    for(int i=1;i<=cnt;i++){
        if(lst<pr[i].fr)lst=pr[i].sc,ans++;
    }
    printf("%lld %lld\n",cnt,m-ans);
}
signed main(){
    freopen("detect.in","r",stdin);freopen("detect.out","w",stdout);
    int _=read();while(_--)
    slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}