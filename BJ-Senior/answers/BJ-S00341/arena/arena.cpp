#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const ll N=1e5+10,M=20;
ll p[M][N],a[N],b[N],c[N],q[N];
ll s[N],n,m,t,tt;
char st[N];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++){
    scanf("%lld",&b[i]);}
    for(ll i=1;i<=m;i++){
    scanf("%lld",&c[i]),c[i];}
    while((1<<tt)<n) tt++;
    for(ll i=tt-1;i>=0;i--){
        scanf("%s",&st);
        for(ll j=1;j<=1<<i;j++){
        p[i][j]=st[j-1]-'0';}//j,s
    }
    if(1<<tt!=n) tt--;
    scanf("%lld",&t);
    while(t--){
        ll x[4];
        for(ll i=0;i<4;i++){
        scanf("%lld",&x[i]);}
        for(ll i=1;i<=n;i++){
        a[i]=b[i]^x[i%4];}//=1
        for(ll i=0;i<=tt;i++){
            for(ll j=1;j<=1<<i;j++) s[j]=j;
            for(ll j=i-1;j>=0;j--){
                q[1<<tt-j-1]=s[1];
                for(ll l=1;l<=1<<j;l++){
                    ll t1=s[l*2-1],t2=s[l*2];
                   // cout<<p[j][l]<<" "<<t1<<" "<<a[t1]<<" "<<endl;
                    if(!p[j][l]&&a[t1]>=i-j) s[l]=t1;
                    if(p[j][l]&&a[t2]<i-j) s[l]=t1;//tt
                    if(!s[l]) s[l]=t2;
                }
            }
            q[1<<i]=s[1];
        }
        for(ll i=1;i<=m;i++){
        printf("%lld\n",q[c[i]]);}
    }
    return 0;
}
