#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,a[100010],b[100010];
long long ans;
bool f[100010];
int erfen(int x){
    int t = 0;
    do{
        t = upper_bound(a + 1,a + n + 1,x) - a;
        x = b[t];
    }
    while(t <= n && (f[t] || b[t] == 0));
    return t;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    ans = n;
    for(int i = 1;i <= n;++i){
        scanf("%d",&a[i]);
        b[i] = a[i];
    }

    for(int i = 1;i <= n;++i){
        sort(a + 1,a + n + 1);
        sort(b + 1,b + 1 + n);
        if(b[i] == 0 || (a[i] == 0 && !f[i])) continue;
        int t = erfen(a[i]);
        if(t > n) continue;
        else{
            f[t] = true;
            a[t] = b[i] = a[i] = 0;
            --ans;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
