#include <bits/stdc++.h>
using namespace std;
long long  numsticks[]={6,2,5,5,4,5,6,3,7,6};
long long  have[131072];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long  t;
    scanf("%lld",&t);
    for (long long i=1;i<=100000;i++){
        long long t=i;
        while (t){
            have[i]+=numsticks[t%10];
            t/=10;
        }
    }
    for (long long  i=1;i<=t;i++){
        long long n;
        scanf("%lld",&n);
        long long ans=-1;
        for (long long j=1;j<=100000;j++)
            if (have[j]==n){
                ans=j;
                break;
            }
        if (n==1)
            printf("-1\n");
        else printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
