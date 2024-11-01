//MAE
#include<bits/stdc++.h>
using namespace std;
#define TY long long
#define IL inline
#define pb push_back
#define MAXN 200005
#define MAXM 200005
#define MAXK 27
#define For(i,a,b) for(TY i=(a);i<=(b);++i)
#define FOR(i,a,b) for(TY i=(a);i<(b);++i)
#define Rof(i,a,b) for(TY i=(a);i>=(b);--i)
#define ROF(i,a,b) for(TY i=(a);i>(b);--i)
IL TY qr(){
    TY u=0,v=1;char ch=getchar();
    while(ch<'0'||ch>'9')v=(ch=='-'?-1:1),ch=getchar();
    while(ch>='0'&&ch<='9')u=(u*10)+(ch-'0'),ch=getchar();
    return u*v;
}IL void qw(TY u){
    if(u<0){putchar('-');u=-u;}
    if(u==0){putchar('0');return;}
    if(u>=10)qw(u/10);putchar(u%10+'0');
}IL void qw(TY u,char ch){qw(u);putchar(ch);}
TY T,n,m,L,V,p[MAXN],tot;
struct node{
    TY beg,v,add;
}s[MAXN];
struct Line{TY u,v;}t[MAXN];
IL bool cmp(Line x,Line y){
    if(x.u==y.u)return x.v>y.v;
    else return x.u<y.u;
}IL double calc(TY v,TY a,TY s){
    if(a==0)return v;
    else return sqrtl(v*v+2*a*s);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    /* init */
    T=qr();while(T--){
        n=qr();m=qr();L=qr();V=qr();
        For(i,1,n)s[i].beg=qr(),s[i].v=qr(),s[i].add=qr();
        For(i,1,m)p[i]=qr();
        For(i,1,n){
            if(s[i].add>=0){
                TY l=1,r=m,ans=0;
                while(l<=r){
                    TY mid=(l+r)>>1;
                    if(s[i].beg<=p[mid]&&calc(s[i].v,s[i].add,p[mid]-s[i].beg)>V){
                        ans=mid,r=mid-1;
                    }else l=mid+1;
                }if(ans)t[++tot]={ans,m};
            }else if(s[i].v>V){
                TY L=0,R=0;
                TY l=1,r=m,ans=0;
                while(l<=r){
                    TY mid=(l+r)>>1;
                    if(s[i].beg>p[mid])l=mid+1;
                    else ans=mid,r=mid-1;
                }L=ans;
                l=1,r=m,ans=0;
                while(l<=r){
                    TY mid=(l+r)>>1;
                    if(s[i].beg>p[mid])l=mid+1;
                    else if(calc(s[i].v,s[i].add,p[mid]-s[i].beg)>V)ans=mid,l=mid+1;
                    else r=mid-1;
                }R=ans;
                if(L<=R&&L&&R)t[++tot]={L,R};
            }
        }qw(tot,' ');
        sort(t+1,t+1+tot,cmp);
        TY ans=0,lst=0;
        For(i,1,tot){
            if(t[i].u<=lst){
                lst=min(lst,t[i].v);
            }else lst=t[i].v,++ans;
        }qw(m-ans,'\n');
        tot=0;
    }return 0;
}