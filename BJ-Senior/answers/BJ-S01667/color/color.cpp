#include <bits/stdc++.h>
using namespace std;
long long t,n,a[200005],b[200005],c[200005],sum[200005],ans;
void dfs(long long x){
    if(x > n){
        return;
    }
    b[x] = 1;
    for(long long j = x-1;j >=1;j--){
        if(b[x] == b[j]){
            if(a[x] == a[j]){
                c[x] = a[x];
            }
            break;
        }
    }
    sum[x] = sum[x-1] + c[x];
    if(sum[x] > ans){
        ans = sum[x];
    }
    dfs(x+1);
    c[x] = 0;
    b[x] = 2;
    for(long long j = x-1;j >=1;j--){
        if(b[x] == b[j]){
            if(a[x] == a[j]){
                c[x] = a[x];
            }
            break;
        }
    }
    sum[x] = sum[x-1] + c[x];
    if(sum[x] > ans){
        ans = sum[x];
    }
    dfs(x+1);
    return;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        for(long long i = 1;i <= n;i++){
            scanf("%lld", &a[i]);
        }
        ans = 0;
        dfs(1);
        printf("%lld\n", ans);
    }
    return 0;
}