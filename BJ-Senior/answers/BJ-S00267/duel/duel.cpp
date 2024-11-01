#include<bits/stdc++.h>
using namespace std;
int n, a[100005], b[100005], c[100005];
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        b[a[i]]++;
    }
    int len = 0, cnt = 0;
    for(int i = 1; i <= 100000; i++){
        if(b[i] != 0){
            len++;
            c[len] = b[i];
            cnt += b[i];
        }
    }
    int ans = 0;
    for(int i = 1; i < len; i++){
        cnt -= c[i];
        if(cnt > c[i]){
            ans += c[i];
        }else{
            ans += cnt;
        }
    }
    printf("%d", n - ans);
    return 0;
}
