#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
int a[N], b[N], cnt[N * 5];//b[i] = yu a[i] zui kao jin de tong se shu
int T, n;
ll ans;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf(" %d",&T);
    while(T--){
        memset(a, 0, sizeof(a));
        memset(cnt, 0, sizeof(cnt));
        scanf(" %d",&n);
        ans = 0;
        for(int i = 1; i <= n; i++){
            scanf(" %d",&a[i]);
            cnt[a[i]]++;
        }
        for(int i = n; i >= 1; i--){
            if(cnt[a[i]] <= 1) continue;
            ans += a[i];
            cnt[a[i]] -= 2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
