#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const ll N=2e5+10,M=1e6+10;
ll a[N],d[N][2],b[M],t,n,m,tp;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n),m=0,tp=0;
        memset(b,0,sizeof(b));
        for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);}
        for(ll i=1;i<=n;i++){
            a[++m]=a[i];
            while(a[i]==a[i+1]) tp+=a[++i];//t
        }
        for(ll i=1;i<=m;i++){//n
            d[i][0]=d[i-1][0],d[i][1]=0;//no0
            ll B=b[a[i]]+1;
            if(B>1) d[i][1]=max(d[B-1][0],d[B][1])+a[i];
            d[i][0]=max(d[i][0],d[i][1]),b[a[i]]=i;
        }
        printf("%lld\n",tp+d[m][0]);//notp,n
    }
    return 0;
}
