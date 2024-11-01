#include<bits/stdc++.h>
using namespace std;
int t, n, a[100], a1[100], a2[100], cnt1, cnt2, ans;
void dfs(int m){
    //printf("%d\n", m);
    if(m > n){
        int sum = 0;
        for(int i = 1; i < cnt1; i++){
            if(a1[i] == a1[i+1]) sum += a1[i];
        }for(int i = 1; i < cnt2; i++){
            if(a2[i] == a2[i+1]) sum += a2[i];
        }/*
        for(int i = 1; i <= cnt1; i++) printf("%d ", a1[i]);
        printf("\n");
        for(int i = 1; i <= cnt2; i++) printf("%d ", a2[i]);
        printf("\n");*/
        ans = max(ans, sum); return;
    }a1[++cnt1] = a[m]; dfs(m+1), cnt1--;
    a2[++cnt2] = a[m]; dfs(m + 1), cnt2--;
}int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n); cnt1 = 0, cnt2 = 0, ans = 0;
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        dfs(1);
        printf("%d\n", ans);
    }
    return 0;
}
