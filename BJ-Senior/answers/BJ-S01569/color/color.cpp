//MAE
#include<bits/stdc++.h>
using namespace std;
#define TY long long
#define IL inline
#define pb push_back
#define MAXN 200005
#define MAXM 1000005
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
TY T,n,a[MAXN],lst[MAXM],dp[MAXN],sum[MAXN];
vector<pair<TY,TY> > e[MAXN];
IL void clear(){
    For(i,1,1000000)lst[i]=0;
    For(i,1,n)e[i].clear();
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    /* init */
    T=qr();while(T--){
        n=qr();
        For(i,1,n)a[i]=qr();
        For(i,1,n){
            if(lst[a[i]]==i-1&&i!=1)dp[i]=dp[i-1]+a[i];
            else if(lst[a[i]])dp[i]=max(dp[i-1],dp[lst[a[i]]+1]+sum[i-1]-sum[lst[a[i]]]+a[i]);
            else dp[i]=dp[i-1];
            lst[a[i]]=i;
            if(a[i]==a[i-1])sum[i]=sum[i-1]+a[i];
            else sum[i]=sum[i-1];
        }qw(dp[n],'\n');
        clear();
    }
    return 0;
}