#include<iostream>
#include<algorithm>
using namespace std;
const long long N = 1e5 + 5;
long long a[N], cnt[N];
long long n;
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%lld", &n);
    for(long long i = 1; i <= n; i ++){
        scanf("%lld", &a[i]);
        cnt[a[i]] ++;
    }
    long long last;
    long long killed = 0, waiting = 0;
    for(long long i = 1; i < N; i ++){
        if(cnt[i]){
            last = i;
            waiting = cnt[i];
            break;
        }
    }
    for(long long i = last+1; i < N; i ++){
        if(cnt[i] == 0) continue;
        killed += min(waiting, cnt[i]);
        waiting -= min(waiting, cnt[i]);
        waiting += cnt[i];
    }
    printf("%lld\n", waiting);
    return 0;
}
