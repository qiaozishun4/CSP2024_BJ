#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long a[200007],sum[200007],ans,dp[200007],buc[1000007],la[200007];
long long w(long long i,long long j){
    if(a[i]==a[j]) return a[i];
    return 0;
}
long long suan(long long l,long long r){
    return sum[r]-sum[l];
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    long long T;
    scanf("%lld",&T);
    while(T--){
        memset(buc,0,sizeof(buc));
        memset(la,0,sizeof(la));
        long long n;
        ans=0;
        scanf("%lld",&n);
        for(long long i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            if(buc[a[i]]) la[i]=buc[a[i]];
            buc[a[i]]=i;
        }
        for(long long i=1;i<=n;i++){
            sum[i]=sum[i-1]+w(i,i-1);
            dp[i]=0;
        }
        for(long long i=1;i<=n;i++){
            dp[i]=max(dp[i],dp[i-1]+w(i-1,i));
            int j;
            if(w(i+1,i)) j=la[i];
            else j=la[i+1];
            dp[i]=max(dp[i],dp[j]+suan(j+1,i)+w(i+1,j));
        }
        printf("%lld\n",dp[n]);
    }
    return 0;
}
/*
1
8
3 5 2 5 1 2 1 4
*/