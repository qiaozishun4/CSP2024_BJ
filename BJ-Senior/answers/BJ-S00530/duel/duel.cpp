#include<bits/stdc++.h>
using namespace std;
const int INF=1e5+1;
long long s[INF];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    for(int i=1;i<=INF;i++){
        s[i]=0;
    }
    long long a,n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a);
        s[a]++;
    }
    long long maxn=-1;
    for(int i=1;i<=INF;i++){
        if(s[i]!=0)printf("%d %lld\n",i,s[i]);
        if(maxn<s[i])maxn=s[i];
    }
    printf("%lld",maxn);
    return 0;
}
