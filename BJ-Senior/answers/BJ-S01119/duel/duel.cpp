#include<bits/stdc++.h>
using namespace std;
int n, a[100005], sum[100005], ans, cnt;
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]); sum[a[i]]++;
    }for(int i = 100000; i >= 1; i--){
        if(sum[i] > cnt){
            ans += sum[i] - cnt; cnt = 0;
        }else cnt -= sum[i];
        cnt += sum[i];
    }printf("%d", ans);
    return 0;
}
