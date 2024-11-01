#include<bits/stdc++.h>
#define LL long long
#define CLR(a,x) memset(a,x,sizeof(a))
using namespace std;
const int N=1e5+5;
const int M=1e6+5;
const int I_INF=2e9+5;
int n,a[N],buc[N],sum;
int main() {
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),buc[a[i]]++;
    for(int i=1;i<=100000;i++) {
        if(buc[i]>=sum)ans+=sum,sum=buc[i];
        else ans+=buc[i];
    }
    printf("%d\n",n-ans);
    return 0;
}
//14:39
