#include <bits/stdc++.h>
using namespace std;
    long long n,r[100005],cnt[100005],ans;
    void dfs(long long x){
        if(x < 1){
            long long ans2 = 0;
            for(long long i = 1;i <= n;i++){
                if(cnt[i] != 1){
                    ans2++;
                }
            }
            if(ans2 <= ans){
                ans = ans2;
            }
            return;
        }
        for(long long i = 1;i <= n;i++){
            if(cnt[i] == 0){
                for(long long j = 1;j <= n;j++){
                    if(i == j || cnt[j] == 1){
                        continue;
                    }else if(r[i] > r[j]){
                        cnt[i] = 2;
                        cnt[j] = 1;
                        dfs(x-2);
                        cnt[i] = 0;
                        cnt[j] = 0;
                    }else if(r[i] <= r[j]){
                        cnt[i] = 2;
                        dfs(x-1);
                        cnt[i] = 0;
                    }
                }
            }else{
                continue;
            }
        }
    }
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%lld", &n);
    ans = n;
    for(int i = 1;i <= n;i++){
        scanf("%lld", &r[i]);
    }
    dfs(n);
    printf("%lld", ans);
    return 0;
}