#include<bits/stdc++.h>
using namespace std;
long long t,n,bj,num[200005],cc[1000005],sum;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%lld",&t);
    for(int t1=1;t1<=t;t1++){
        sum=0;
        memset(cc,0,sizeof(cc));
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&num[i]);
            cc[num[i]]++;
        }
        for(int i=1;i<=1000000;i++){
            bj=cc[i]/2;
            sum+=(i*bj);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
