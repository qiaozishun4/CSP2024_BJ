//MAE
#include<bits/stdc++.h>
using namespace std;
#define TY int
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
TY n,a[MAXN];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    /* init */
    n=qr();
    For(i,1,n)a[i]=qr();
    sort(a+1,a+1+n);
    TY ans=0,cnt=0,lst=0,t=0;
    For(i,1,n){
        if(a[i]!=lst){
            lst=a[i];
            cnt+=t;t=0;
        }if(cnt)--cnt,++ans;
        ++t;
    }qw(n-ans);
    return 0;
}